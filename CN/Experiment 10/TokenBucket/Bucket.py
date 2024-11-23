import socket
import time
import threading

HOST = '0.0.0.0'
PORT = 12345
LEAK_RATE = .5
MAX_SIZE = 10

tokens = []
received_data = []
generate_tokens = True
continue_leaking = True

def generate_token():
	while generate_tokens:
		if len(tokens) < MAX_SIZE:
			tokens.append("*")
		time.sleep(1 / LEAK_RATE)
	tokens.clear()

def leaky():
	while continue_leaking or len(received_data) > 0:
		if len(received_data) > 0:
			leaked = received_data.pop(0)
			print('Leaked:', leaked)
			print('Remaining:', received_data)
		print('Tokens:', len(tokens))

		time.sleep(1 / LEAK_RATE)
	if not continue_leaking:
		print('Leak stopped')

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((HOST, PORT))
s.listen()
print('Server started at', s.getsockname())
token_gen_thread = threading.Thread(target=generate_token)
leak_thread = threading.Thread(target=leaky)
token_gen_thread.start()
leak_thread.start()
conn, addr = s.accept()
print('Connected by', addr)
while True:
	data = conn.recv(1024)
	if not data:
		break
	if data.decode() == 'exit':
		generate_tokens = False
		continue_leaking = False
		s.close()
		print('Host stopped')
		break
	data = data.decode()
	if len(tokens) > 0:
		tokens.pop(0)
		received_data.append(data)
		conn.sendall(f'Acknowleged {data}'.encode())
	else:
		conn.sendall(b'No tokens available')
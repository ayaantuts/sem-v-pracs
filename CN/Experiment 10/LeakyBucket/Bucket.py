import socket
import time
import threading

HOST = '0.0.0.0'
PORT = 12345
LEAK_RATE = .5
MAX_SIZE = 5

received_data = []
continue_leaking = True

def leaky():
	while continue_leaking or len(received_data) > 0:
		if len(received_data) > 0:
			leaked = received_data.pop(0)
			print('Leaked:', leaked)
			print('Remaining:', received_data)
		else:
			print('Bucket is empty')
		time.sleep(1 / LEAK_RATE)
	if not continue_leaking:
		print('Leak stopped')

leak_thread = threading.Thread(target=leaky)

def main():
	s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	s.bind((HOST, PORT))
	s.listen(1)
	print('Listening on', PORT)
	conn, addr = s.accept()
	print('Connected by', addr)
	while True:
		data = conn.recv(1024)
		if not data or data == b'exit':
			conn.close()
			globals().update(continue_leaking=False)
			break
		if len(received_data) < MAX_SIZE:
			received_data.append(data.decode())
			conn.sendall(f'Received: {data}'.encode())
		else:
			conn.sendall(b'Bucket is full')

leak_thread.start()
main()
import socket
import time
import random

HOST = '0.0.0.0'
PORT = 12345
WAIT_TIME = 1

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((HOST, PORT))
s.listen()
conn, addr = s.accept()
print('Connected by', addr)
while True:
	data = conn.recv(1024)
	if not data:
		break
	if data.decode() == 'exit':
		break
	time.sleep(WAIT_TIME)
	print(f'Received \'{data.decode()}\'')
	time.sleep(WAIT_TIME)
	if random.choice([True, False]):
		print(f'Sent ACK for \'{data.decode()}\'')
		conn.sendall(f'ACK'.encode())
	else:
		print(f'Sent NACK for \'{data.decode()}\'')
		conn.sendall(f'NACK'.encode())

conn.close()
s.close()

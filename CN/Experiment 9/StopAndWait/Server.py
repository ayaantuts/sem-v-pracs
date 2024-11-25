import socket
import time
import random

HOST = '0.0.0.0'
PORT = 12345

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((HOST, PORT))
s.listen()
conn, addr = s.accept()
print('Connected by', addr)
while True:
	data = conn.recv(1024)
	if not data or data.decode() == 'exit':
		print("Client has closed connection")
		conn.close()
		break
	time.sleep(1)
	if random.choice([True, False]):
		print(f'Sent ACK for \'{data.decode()}\'')
		conn.sendall(f'ACK'.encode())
	else:
		print('Data lost: Sending NACK')
		conn.sendall(f'NACK'.encode())

s.close()

import socket
import time

WAIT_TIME = 1

socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
socket.connect(('127.0.0.1', 12345))

while True:
	message = input('Enter message: ')
	time.sleep(1)
	socket.send(message.encode())
	if message == 'exit':
		break
	print(f'Sent \'{message}\'')
	print('Waiting for acknowledgement')
	time.sleep(1)
	data = socket.recv(1024)
	if data.decode() == 'ACK':
		print('Received', data.decode())
	else:
		while data.decode() == 'NACK':
			print(f'Resending data {message}')
			socket.send(message.encode())
			data = socket.recv(1024)

socket.close()
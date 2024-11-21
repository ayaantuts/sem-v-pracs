import socket
import time

Tp = 2
Tf = .5

socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
socket.connect(('127.0.0.1', 12345))

while True:
	message = input('Enter message: ')
	time.sleep(Tf)
	socket.send(message.encode())
	if message == 'exit':
		break
	print(f'Sent \'{message}\'')
	print('Waiting for acknowledgement')
	time.sleep(Tp)
	data = socket.recv(1024)
	print('Received', data.decode())

socket.close()
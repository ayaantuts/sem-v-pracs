import socket
import time

HOST = '0.0.0.0'
PORT = 12345
Tp = 2
Tf = .5

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((HOST, PORT))
s.listen(1)
conn, addr = s.accept()
print('Connected by', addr)
while True:
	data = conn.recv(1024)
	if not data:
		break
	if data.decode() == 'exit':
		break
	print(f'Received \'{data.decode()}\'')
	time.sleep(Tf)
	print(f'Sent ACK for \'{data.decode()}\'')
	time.sleep(Tp)
	conn.sendall(f'ACK for \'{data.decode()}\''.encode())

conn.close()
s.close()

import socket

HOST = '127.0.0.1'
PORT = 12345

def main():
	s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	s.connect((HOST, PORT))
	while True:
		data = input('Enter data to send: ')
		s.sendall(data.encode())
		if data == 'exit':
			s.close()
			break
		data = s.recv(1024)
		print('Received', data.decode())

if __name__ == '__main__':
	main()
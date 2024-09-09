import socket

domain_name = input("Enter the domain name: ")
try:
	ip = socket.gethostbyname(domain_name)
except(socket.gaierror):
	print("Invalid domain name")
	exit()
print(f"IP address of {domain_name} is {ip}")
octets = ip.split('.')
octets = list(map(int, octets))
no_of_octets:int

if octets[0] >= 0 and octets[0] <= 127:
	print("Class A")
	no_of_octets = 1
elif octets[0] >= 128 and octets[0] <= 191:
	print("Class B")
	no_of_octets = 2
elif octets[0] >= 192 and octets[0] <= 223:
	print("Class C")
	no_of_octets = 3
elif octets[0] >= 224 and octets[0] <= 239:
	print("Class D")
	no_of_octets = 4

else:
	print("Invalid class")
	exit()

subnet_mask = [255] * no_of_octets

networkip = ''
for i in range(no_of_octets):
	networkip += str(subnet_mask[i] & octets[i]) + '.'

print(f"Network IP address is {networkip[:-1] + '.0' * (4 - no_of_octets)}")
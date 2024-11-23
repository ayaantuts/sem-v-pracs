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
	print("Which belongs to Class A")
	no_of_octets = 1
elif octets[0] >= 128 and octets[0] <= 191:
	print("Which belongs to Class B")
	no_of_octets = 2
elif octets[0] >= 192 and octets[0] <= 223:
	print("Which belongs to Class C")
	no_of_octets = 3
elif octets[0] >= 224 and octets[0] <= 239:
	print("Which belongs to Class D")
	no_of_octets = 4
elif octets[0] >= 240 and octets[0] <= 255:
	print("Which belongs to Class E")
	print("--- Special (Reserved) Address ---")
	exit()
else:
	print("Invalid class")
	exit()

subnet_mask = [255] * no_of_octets + [0] * (4 - no_of_octets)
networkip = []
for i in range(4):
	networkip.append(str(octets[i] & subnet_mask[i]))
print(f"The network ip is {'.'.join(networkip)}")
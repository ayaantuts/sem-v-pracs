# Generator
data = input('Enter data(4 bit only): ')
parity = int(input('Enter 0 for even parity and 1 for odd parity: '))

d4 = int(data[0])
d3 = int(data[1])
d2 = int(data[2])
d1 = int(data[3])

p1 = ((d1 + d2 + d4) % 2) ^ parity
p2 = ((d1 + d3 + d4) % 2) ^ parity
p4 = ((d2 + d3 + d4) % 2) ^ parity

final = [d4, d3, d2, p4, d1, p2, p1]
final = [str(i) for i in final]
print(f"Data to be transmitted: {''.join(final)}")

# Checker
received_data = input('Enter received data(7 bit only): ')
parity = int(input('Enter 0 for even parity and 1 for odd parity: '))

d4 = int(received_data[0])
d3 = int(received_data[1])
d2 = int(received_data[2])
p4 = int(received_data[3])
d1 = int(received_data[4])
p2 = int(received_data[5])
p1 = int(received_data[6])

c4 = (d4 + d3 + d2 + p4) % 2
c2 = (d4 + d3 + d1 + p2) % 2
c1 = (d4 + d2 + d1 + p1) % 2

error = c4 * 4 + c2 * 2 + c1
if error == 0:
	print('No error')
else:
	print(f'Error at position {error} (from right)')
	received_data = list(received_data)
	received_data[7 - error] = str(int(received_data[7 - error]) ^ 1)
	received_data = ''.join(received_data)
	print(f'Corrected data: {received_data}')
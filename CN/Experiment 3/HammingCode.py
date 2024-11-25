def calculateParityBits(n):
	i = 0
	while 2**i < n + i + 1:
		i += 1
	return i

def returnParityBits(n):
	i = 0
	while 2**i < n + 1:
		i += 1
	return i

def generateParityBits(data, check_bit, parity):
	count = 0
	for i in range(len(data)):
		if (len(data) - i) & check_bit:
			count += int(data[i])
	if parity == 0:
		if count % 2 == 0:
			return 0
		else:
			return 1
	else:
		if count % 2 == 0:
			return 1
		else:
			return 0

# Generator
data = input("Enter data: ")
noOfParity = calculateParityBits(len(data))
print(f"Number of parity bits required: {noOfParity}")
parity = int(input("Enter parity (0 for even, 1 for odd): "))
parity_pos = [2**i for i in range(noOfParity)]
final = ['0'] * (len(data) + noOfParity)
j = 1
for i in range(1, len(final) + 1):
	if i in parity_pos:  # Check if i is a power of 2
		continue
	final[-i] = data[-j]
	j += 1

for i in range(noOfParity):
	final[-parity_pos[i]] = str(generateParityBits(final, parity_pos[i], parity))

print(f"Data with parity bits: {''.join(final)}")

# Checker
received_data = input("Enter received data: ")
noOfParity = returnParityBits(len(received_data))
print(f"Number of parity bits: {noOfParity}")
parity = int(input("Enter parity (0 for even, 1 for odd): "))
error = 0

for i in range(noOfParity):
	if generateParityBits(received_data, i, parity):
		error += 2**i

if error:
	print(f"Error at position {error} (from right)")
	received_data = list(received_data)
	received_data[-error] = str(int(received_data[-error]) ^ 1)
	received_data = ''.join(received_data)
	print(f"Corrected transmission sequence: {received_data}")
else:
	print("No error")
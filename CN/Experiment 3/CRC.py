# This code consists of two parts:
# 1. Sender side: It takes the data and generator polynomial as input and calculates the CRC
# 2. Receiver side: It takes the received data and generator polynomial as input and checks for errors
# Sender side:
data = input('Enter the data: ')
original_data = data
generator = input('Enter the generator polynomial: ')
data = list(data)
generator = list(generator)
for i in range(len(generator) - 1):
	data.append('0')

def xor(a, b):
	if a == b:
		return '0'
	return '1'

def calcRemainder(data, generator):
	# curr = the part of data that is currently being divided
	curr = []
	pointer = 0
	while pointer < len(generator):
		curr.append(data[pointer])
		pointer += 1

	while pointer < len(data):
		if curr[0] == '1':
			for i in range(len(generator)):
				curr[i] = xor(curr[i], generator[i])
		curr.pop(0)
		curr.append(data[pointer])
		pointer += 1
	# This if is for the last iteration, as we don't want to append anything further
	# If we keep it in the loop, it will give Index out of range error
	if curr[0] == '1':
		for i in range(len(generator)):
			curr[i] = xor(curr[i], generator[i])
	curr.pop(0)
	return curr

remainder = calcRemainder(data, generator)
crc = original_data + ''.join(remainder)
print('Remainder:', ''.join(remainder))
print('CRC:', crc)
print()

# Receiver side:
received_data = input('Enter the received data: ')
received_generator = input('Enter the generator polynomial: ')
received_data = list(received_data)
generatorR = list(received_generator)
remainderR = calcRemainder(received_data, generatorR)
error = False
for r in remainderR:
	if r == '1':
		error = True
		break

if error:
	print('Error detected')
else:
	print('No error detected')
	original_dataR = received_data[:len(received_data) - len(generatorR) + 1]
	print('Original data:', ''.join(original_dataR))
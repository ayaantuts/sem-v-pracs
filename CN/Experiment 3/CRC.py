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
	while len(data) >= len(generator):
		if data[0] == '1':
			for i in range(len(generator)):
				data[i] = xor(data[i], generator[i])
		while data and data[0] == '0':
			data.pop(0)
	while len(data) < len(generator) - 1:
		data.insert(0, '0')
	return data

remainder = calcRemainder(data, generator)
crc = original_data + ''.join(remainder)
print('Remainder:', ''.join(remainder))
print('CRC:', crc)
print()

# Receiver side:
received_data = input('Enter the received data: ')
received_generator = input('Enter the generator polynomial: ')
original_dataR = received_data[:len(received_data) - len(received_generator) + 1]
received_data = list(received_data)
received_generator = list(received_generator)
remainderR = calcRemainder(received_data, received_generator)

if '1' in remainderR:
	print('Error detected')
else:
	print('No error detected')
	print('Original data:', original_dataR)
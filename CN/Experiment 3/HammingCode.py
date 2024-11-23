def calculateParityBits(n):
	i = 0
	while 2**i < n + i + 1:
		i += 1
	return i

def generateParityBits(data, pNum, parity):
	parityBit = 0
	count = 0
	for i in range(len(data) + 1):
		# len(data) - i is the position of parity bit (because we are adding parity bits to the end)
		if (len(data) - i) & (1 << pNum):
			if data[i] == 1:
				count += 1
	# 0 for even parity, 1 for odd parity, if count and parity are same (even/odd), then parity bit is 0, else 1
	if parity ^ (count % 2):
		parityBit = 1
	return parityBit

data = input("Enter data: ")
noOfParity = calculateParityBits(len(data))
print(f"Number of parity bits required: {noOfParity}")
parity_pos = [2**i for i in range(noOfParity)]
parity = int(input("Enter parity (0 for even, 1 for odd): "))

final = [0] * (len(data) + noOfParity)
j = 0
for i in range(len(final)):
	if len(final) - i in parity_pos:
		final[i] = -1
	else:
		final[i] = int(data[j])
		j += 1
	
for i in range(noOfParity):
	final[len(final) - parity_pos[i]] = generateParityBits(final, i, parity)

final = [str(i) for i in final]
print(f"Data with parity bits: {''.join(final)}")

# Example with explanation
"""
Given:
Data = 1011
Parity = 0 (even)

Solution:
Number of parity bits required = 3

Without parity bits:
 1  | 0  | 1  | _  | 1  | _  | _    (Data)
 D4 | D3 | D2 | P4 | D1 | P2 | P1   (Representation)
 7  | 6  | 5  | 4  | 3  | 2  | 1    (Position)
 0  | 1  | 2  | 3  | 4  | 5  | 6    (Indexing)

For P1:
We check positions which have 1 at 1st bit from right (in binary representation)
Hence, we check (1, 3, 5, 7)

For P2:
We check positions which have 1 at 2nd bit from right
Hence, we check (2, 3, 6, 7)

For P4:
We check positions which have 1 at 4th bit from right
Hence, we check (4, 5, 6, 7)

Therefore, P1 = 1, P2 = 0, P4 = 0
Data with parity bits = 1010101
"""
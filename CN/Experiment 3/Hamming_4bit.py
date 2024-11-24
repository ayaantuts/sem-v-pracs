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
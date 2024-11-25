import random
import time

total_seq  = int(input('Enter the sequence numbers: '))
window_size = total_seq // 2

data = [i for i in range(total_seq)]
ack = [False] * total_seq
ack_received = 0
window = data[:window_size]
curr_window = window_size

while ack_received < total_seq:
	window = list(filter(lambda i: not ack[i], window))
	while len(window) < window_size and curr_window < total_seq:
		window.append(curr_window)
		curr_window += 1

	for i in window:
		print(f"Sending packet: {i}")
		time.sleep(1)

	for i in window:
		if not random.choice([True, False]):
			print(f"Packet lost: {i}")
			break
		else:
			print(f"Acknowledgement received: {i}")
			ack_received += 1
			ack[i] = True
		time.sleep(1)
frames = []
no_of_frames = int(input("Enter the number of frames: "))
for i in range(no_of_frames):
	frame = input("Enter the frame data: ")
	frames.append(str(len(frame) + 1))
	frames.append(frame)

message = ''.join(frames)
print("The message after framing is:", message)
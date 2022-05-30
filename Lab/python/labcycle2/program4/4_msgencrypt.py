key = int(input("Enter key : "))
msg = input("Enter message : ")
#print(f"ascii of z = {ord('z') }")
for letter in msg:
	#print(f"ascii of {letter} = {ord(letter) }")
	if letter == " ":
		print(" ",end="")
	elif (ord(letter)+key)>ord("z"):
		print(chr((ord(letter)+key)%26),end="")
	else:
		print(chr(ord(letter)+key),end="")
print("")

print("\nEnter q to exit",end="\n\n")
lst = []
while True:
	num = input("Enter number : ")
	if num == 'q':
		break
	elif num =="":
		pass
	else:
		num = int(num)
		if num>100:
			lst.append("over")
		else:		
			lst.append(num)
print(f"List {num} created => {lst}",end="\n\n")

limit = int(input("Enter limit : "))
for i in range(1,limit+1):
	if i<=(limit+1)//2:
		for j in range(i):
			print(f" * ",end="")
	else :
		for j in range(limit+1-i):		
			print(f" * ",end="")
	print("") 
		 

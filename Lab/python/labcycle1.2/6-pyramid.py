element = int(input("Enter a number : "))
for i in range(1,element+1):
	temp=i
	while temp<=i*i:
		print(temp,end=" ")
		temp=temp+i
	print()
	#print("*"*i)	
	#while temp<=i*i:
	#	print(temp," ")
	#	temp=temp*2

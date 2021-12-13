number = int(input("Enter a number : "))
n1 =-1
n2 =1
for i in range(number):
	sum1 = n1+n2
	if sum1>number : # checking sum less than entered number
		break	
	print(f" {sum1} ")
	n1 = n2
	n2 = sum1
	


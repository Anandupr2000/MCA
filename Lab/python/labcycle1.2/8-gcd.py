n1 = int(input("Enter 1st number : "))
n2 = int(input("Enter 2nd number : "))
i=1
print("Common factors found are :",end=" ")
while i < (n1%i==0) and i < (n2%i==0):
	print(f" {i}",end=" ")
	i = i+1
else:
	print("No common factor found")

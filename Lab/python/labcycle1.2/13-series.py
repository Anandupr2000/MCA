n = int(input("Enter limit : "))
print("Series is =>",end="")
sum1=0.0
for i in range(1,n+1):
	sum1 = sum1 + (i/(i+1)) # summing terms
	
	# printing term
	print(f" {i}/{i+1}",end="")
	if i != n:	
		print(f" +",end="")
	else:
		print("")
print(f"Sum of series = {sum1}")

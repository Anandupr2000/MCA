n = int(input("Enter a number : "))
i=1
print(f"\nFactors of {n} are",end=" ")
while i <= n:
	if n%i is 0:
		print(i,end=" ")
	i=i+1
print()

num = int(input("Enter a number :"))
num1 = num
rev=0
while num > 0:
	rem = num%10
	rev = rev*10+rem
	num = num//10	
print(f"Reverse of {num1} is {rev}")

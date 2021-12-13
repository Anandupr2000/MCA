num = int(input("Enter a number : "))
temp = num
rem = 0
cube = 0
while num>0:
	rem = num%10
	cube = cube+(rem*rem*rem)
	num = num//10
if temp==cube:
	print(f"{temp} is armstrong")
else:
	print(f"{temp} is not armstrong")

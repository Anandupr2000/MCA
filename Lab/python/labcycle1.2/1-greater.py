#[num1,num2,num3] = input("Enter 3 numbers : ").split(" ") #for entering values in a straight line 

print("Enter 3 numbers : ")
num1 = int(input())
num2 = int(input())
num3 = int(input())

if(num1>num3):
	if(num1>num2):	
		print(f"{num1} is greater.")
	elif(num1<=num2):
		print(f"{num2} is greater.")
else:
	if(num3>num2):	
		print(f"{num3} is greater.")
	elif(num3<=num2):
		print(f"{num2} is greater.")

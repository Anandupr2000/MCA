limit = int(input("Enter limit for entering elements : "))
sum1 =0
lst=[]
for i in range(limit):
	lst.append(int(input("Enter element : ")))
for i in lst:
	sum1 = sum1 + i
print(f"List is {lst}")
print(f"Sum of elements in list is : {sum1}")

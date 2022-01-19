lst = []
lstEven = []

print("\nEnter q to exit")
while True:
    element = input("\nEnter integer : ")
    if(element =='q'):
        break
    element = int(element)
    if element>=0:
        lst.append(element) 
print(f"original list : {lst}")
print()
for i in lst:
    if i%2!=0:
        lstEven.append(i)
        
print(f"list without even numbers : {lstEven}")
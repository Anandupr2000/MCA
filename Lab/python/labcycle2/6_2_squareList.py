limit = int(input("Enter limit : "))
numList = []
for i in range(limit):
	numList.append(int(input(f"Enter {i+1} number : ")))
numList = [x*x for x in numList]

print(numList)

numLst1 = []
numLst2 = []

print(f"\nEnter q to quit")

for i in range(2):# range(2) since there are 2 list to be reed
	while True:# reading values for each list
		element = input(f"\nEnter number for list{i+1} : ");
		if(element=='q'):
			break
		if i == 0:
			numLst1.append(int(element))
		elif i == 1:
			numLst2.append(int(element))

print(numLst1)
print(numLst2)

if(len(numLst1)==len(numLst2)):
	print("\n2 list are of same length")
else:
	print("\n2 list have different length")

#checking for both list sum equality
if(sum(numLst1)==sum(numLst2)):
	print("\nElements in 2 lists have same sum")
else:
	print("\n2 list have different sum")

common = False
for i in numLst1:
	if i in numLst2:
		common = True
		if(i==numLst1[len(numLst1)-1]):
			print(f"{i}",end="")
		else:
			print(f"{i},",end="")
if common:
	print(" are common found")
else:
	print("no common")
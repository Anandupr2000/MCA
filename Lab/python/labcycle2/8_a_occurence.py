firstNameLst = []
print("\nEnter q to stop")
# storing name in list
while True:
	w = input("Enter name : ")
	if w == "q":
		break
	firstNameLst.append(w)

#count number of 'a' inside each name in firstNameLst
aCount = 0
for name in firstNameLst:
	for letter in name:
		if letter == "a":
			aCount = aCount + 1
print(f"No of times 'a' occured = {aCount}")
	

sList = input("Enter a line of text : ").split(" ")
print(f"Converted to list => {sList}")

sDict = {}
for i in range(len(sList)):
	count = 1
	word = sList[i]
	if sList[i] in sDict:	
		sDict[word] = count+1
	else:
		sDict[word] = count
print(sDict)

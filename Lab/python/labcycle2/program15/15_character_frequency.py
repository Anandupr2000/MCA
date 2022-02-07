w = input("\nEnter a string : ")
wDict = {}

for i in w:
    if i in wDict:
        wDict[i] = wDict[i]+1
    else:
        wDict[i] = 1;
        
print(wDict) # showing no of times each character appeared
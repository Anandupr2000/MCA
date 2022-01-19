wLst = input("Enter word :")
print(f"\nEntered string is : {wLst}")
wLst = list(wLst) # spliting string to list
print(wLst)
f = wLst[0]
w=''
for i in range(len(wLst)):
    if i!=0:
        if f == wLst[i]:
            wLst[i]='$'
    w = w+wLst[i]
    
print(f"\nAfter manipulation, string is : {w}")
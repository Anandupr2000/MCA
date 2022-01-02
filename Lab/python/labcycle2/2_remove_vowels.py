stringList = input("Enter a text : ").split();
for i in stringList:
    for j in i:
        if(j not in ["a","e","i","o","u","A","E","I","O","U"]):
            print(j,end="")
    print("",end=" ")
print("")

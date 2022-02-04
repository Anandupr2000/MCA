
obj = open("file1.txt","r")
lst = obj.readlines()
obj2 = open("file2.txt","w")
for i in range(0, len(lst)):
    if i%2 ==0:
        obj2.write(lst[i])
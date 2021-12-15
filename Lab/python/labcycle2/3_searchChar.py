string  = input("Enter a text : ")
c = input("Enter a character : ")[0]
found  = False
for i in range(0,len(string)):
    if c is string[i]:
        found = True
        break
if found:
    print(f"{c} found at index position {i} of {string}")
else:
    print(f"{c} not found")
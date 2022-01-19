string = input("\nEnter a string : ")
r = ''
print(string[len(string)-3:])
if 'ing' == string[len(string)-3:]: 
    r = string[0:len(string)-3]+'ly'
else:
    r = string+'ing'
print(f"\nEntered string : {string}")
print(f"String after manipulation : {r}") 
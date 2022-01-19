str1 = input("\nEnter 1st string : ")
str2 = input("\nEnter 2nd string : ")

# using slice operator
print(str1[0:1]+str2[1]+str1[2:]+" "+str2[0:1]+str1[1]+str2[2:])

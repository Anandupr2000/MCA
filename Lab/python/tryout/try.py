# letter = input("Enter a character : ")[0]
# if letter in "aeiouAEIOU":
#     print(f"{letter} is vowel")
# else:
#     print(f"{letter} is not vowel")

# vowelList = [x for x in input("Enter a word :")if x in "aeiouAEIOU"]
# print(vowelList)
# try:
    # f = open("file.txt",'r')
# except Exception:
# f= open("file.txt",mode='w',encoding="cp1252")
# f.write("Hey")
# f = open("file.txt","r")
# print(f.read())
# f.close()

# set1 = {1,2,3}
# set2 = {3,4,5}
# set1.update([-1,34,0])
# print(set1)

# class eg:
#     def __init__():
#         pass
    
#     def __mul__(a, b):

# from numbers import Number
# import string
# from typing import Sequence

# print(isinstance("1",str))

def avg(scores):
    assert len(scores)!=0,"Empty list"
    return sum(scores)/len(scores)
scores2 = [67,59,86,75,92]
print("The Average of scores2:",avg(scores2))
scores1 = []
print("The Average of scores1:",avg(scores1))
lst = []
lW = ''

print("\nEnter q to quit")
# reading words from user
while True:
    element = input("\nEnter word : ")
    if element == 'q':
        break
    lst.append(element)

# sorting list of words according to length
for i in lst:
    if len(i)> len(lW):
        lW = i

print(lst)
print(f"\nLongest word entered is : {lW}")
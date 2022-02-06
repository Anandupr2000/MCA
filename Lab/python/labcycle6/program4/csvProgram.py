obj = open("cars.csv", "r") # opening csv file
col = int(input("Enter column number: "))
obj1 = []
for x in obj:
    obj1.append(x.split(','))
for x in obj1:
    print(x[col-1]) # printing specific col
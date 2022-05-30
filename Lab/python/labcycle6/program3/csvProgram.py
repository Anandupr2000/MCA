from operator import imod


obj = open("cars.csv", "r") # opening csv file
print(obj.readlines()) # printing content as list of string

# import csv
# with open("cars.csv",newline=" ") as csvfile:
#     data = csv.reader(csvfile,delimiter="",quotechar="1")
#     for row in data:
#         print(','.join(row))
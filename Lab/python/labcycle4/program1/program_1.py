import datetime
import time
import calendar
import string
import math

# using string module
str1 = string.punctuation # punctuation
str2 = string.digits
print(f"punctuations in string module = {str1}") 
print(f"digits in string module = {str2}") 


# using time module
# print("Using time module")
ctime =  time.time()
# print(type(t))


# using datatime module
print("Using datetime module")
print("Using datetime.date.today() fn to and print todays date")
d = datetime.date.today() # returns date of today
print(d) 
d = datetime.date.today().day # returns date of the month
m = datetime.date.today().month # returns month of the year
y = datetime.date.today().year # returns year
print(f"today => {d}-{m}-{y}") 

print("Using datetime.time fn to set time to (01h:02m:03s) and print it")
t = datetime.time(1,2,3)
print(f"time => {t}")
print(f"hour => {t.hour}")
print(f"minute => {t.minute}")
print(f"seconds => {t.second}")

# using calendar module
print("Using calender module to print year 2022")
d =  calendar.calendar(2022,2,1,6)
print(d)
# c = calendar.firstweekday()
# c = calendar.Calendar.iterweekdays(c)
# print(c)

print("Using math module")
num = 3
sqr = math.pow(num,2)
print(f"square of {num} is {sqr}")
print(f"square root of {sqr} is {math.sqrt(sqr)}")


print(f"Time taken for program execution = {time.time()-ctime}")
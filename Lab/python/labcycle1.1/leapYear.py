sYear = int(input("Enter start year : "))
eYear = int(input("Enter end year : "))
print(f"Leap years between {sYear} and {eYear} are : ")

while sYear<=eYear:
	if sYear%4==0 and (sYear%400==0 or sYear%100!=0):
		print(f"{sYear}")
	sYear = sYear+1


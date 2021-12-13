basicPay = int(input("Enter basic salary : "))
hra = basicPay*0.1
ta = basicPay*0.05
print(f"Calculating House Rent Allowance(HRA) and Travel Allowance(TA)\nHRA = {hra}\nTA = {ta}")
finalSalary = basicPay+hra+ta
print(f"Final salary of employee after adding HRA, TA is {finalSalary}")

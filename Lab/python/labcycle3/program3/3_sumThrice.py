def calculateSum(num1, num2,num3):
    return num1+num2+num3;

def main():
    num1 = int(input("\nEnter number1 : "))
    num2 = int(input("\nEnter number2 : "))
    num3 = int(input("\nEnter number3 : "))
    
    if(num1 == num2 == num3):
        sum1 = calculateSum(num1,num2,num3)*3
        print("\nEntered numbers are equal")
    else:
        print("\nEntered numbers are not equal")
        sum1 = calculateSum(num1, num2, num3)
    print(f"\nsum = {sum1}")
main()
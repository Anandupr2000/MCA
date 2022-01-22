def calculateSum(num1, num2,num3):
    return 3* num1;

def main():
    num1 = int(input("\nEnter number1 : "))
    num2 = int(input("\nEnter number2 : "))
    num3 = int(input("\nEnter number3 : "))
    
    if(num1 == num2 == num3):
        sum1 = calculateSum(num1, num2, num3)
        print(f"sum = {sum1}")
    else:
        print("\nEntered numbers are not equal")
    
main()
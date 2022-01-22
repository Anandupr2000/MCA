def fact(num):
    if (num == 0) or (num ==1):
        return 1
    else:
        return num*fact(num-1)

def series(limit):
    sum1 = 0
    num = 1
    print("\nSeries => ",end="")
    while num<=limit+1:
        numerator = num**num
        denominator = fact(num)
        sum1 = sum1 + (numerator/denominator)
        
        if(num==limit):
            print(f"{numerator}/{denominator}",end="")
            break
        else:
            print(f"{numerator}/{denominator} + ",end="")
            num = num+1
        
    print(f"\nSum = {sum1}")
    
def main():
    num = int(input("\nEnter limit : "))
    series(num)
    
main()
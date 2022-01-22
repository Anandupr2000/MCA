def evenOrOdd(num):
    if num > 0:
        if num%2 == 0:
            print(f"\n{num} is even")
        else:
            print(f"\n{num} is odd")
    else:
        print(f"\n{num} is neither even nor odd")
        
def main():
    evenOrOdd(int(input("\nEnter a number : ")))
    
main()
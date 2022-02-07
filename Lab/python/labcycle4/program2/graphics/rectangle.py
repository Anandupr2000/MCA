def area(x,y):
    return x*y
def perimeter(x,y):
    return 2*x*y
def main():
    l = int(input("\nEnter length of rectangle : "))
    b = int(input("\nEnter breadth of rectangle : "))
    print(f"\nArea of rectangle with length {l} and breadth {b} is {area(l,b)}")
    print(f"\nPerimeter of rectangle with length {l} and breadth {b} is {perimeter(l,b)}")
    
if __name__ == "__main__":
    main()
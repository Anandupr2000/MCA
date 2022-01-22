areaSquare = lambda x:x*x
areaRect = lambda x,y:x*y
areaTriangle = lambda h,b:(h*b)//2

def main():
    l = int(input("\nEnter one side length : "))
    aSquare = areaSquare(l)
    print(f"\nArea of square with length {l} = {aSquare}")
    l = int(input("\nEnter length of rectangle : "))
    b = int(input("\nEnter breadth of rectangle : "))
    aRect = areaRect(l,b)
    print(f"\nArea of rectangle with length {l} and breadth {b} = {aRect}")
    l = int(input("\nEnter height of triangle : "))
    b = int(input("\nEnter base of triangle : "))
    aTriangle = areaTriangle(l,b)
    print(f"\nArea of triangle with length {l} and breadth {b} = {aTriangle}")
    
    
main()
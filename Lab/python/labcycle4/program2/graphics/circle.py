import math
def area(r):
    return r*r*math.pi
def perimeter(r):
    return 2*r*math.pi
def main():
    r = int(input("\nEnter radius of circle : "))
    print(f"\nArea of circle with radius {r} is {area(r)}")
    print(f"\nPerimeter of circle with radius {r} is {perimeter(r)}")
    
if __name__ == "__main__":
    main()
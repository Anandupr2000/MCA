import math
def surfaceArea(x):
    return 4*x*x*math.pi

def perimeter(x):
    return 2*x*math.pi

def main():
    r = int(input("\nEnter radius of sphere : "))
    print(f"\nArea of sphere with length {r} is {surfaceArea(r)}")
    print(f"\nPerimeter of sphere with length {r} is {perimeter(r)}")
   
if __name__ == "__main__":
    main()
def surfaceArea(x,y,z):
    return 2*(x*y+x*z+y*z)

def perimeter(x,y,z):
    return 4*(x+y+z)

def main():
    l = int(input("\nEnter length of cuboid : "))
    b = int(input("\nEnter breadth of cuboid : "))
    h = int(input("\nEnter heigth of cuboid : "))
    print(f"\nArea of cuboid with length {l}, breadth {b} and height {h} is {surfaceArea(l,b,h)}")
    print(f"\nPerimeter of cuboid with length {l}, breadth {b} and height {h} is {perimeter(l,b,h)}")
   
if __name__ == "__main__":
    main()
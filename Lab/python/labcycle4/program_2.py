from graphics import circle,rectangle
from graphics.graphics3d import cuboid,sphere
# print(circle.area(6))
def main():
    # demonstrating circle module
    r = int(input("\nEnter radius of circle : "))
    print(f"\nArea of circle with radius {r} is {circle.area(r)}")
    print(f"\nPerimeter of circle with radius {r} is {circle.perimeter(r)}")
    
    # demonstrating rectangle module
    l = int(input("\nEnter length of rectangle : "))
    b = int(input("\nEnter breadth of rectangle : "))
    print(f"\nArea of rectangle with length {l} and breadth {b} is {rectangle.area(l,b)}")
    print(f"\nPerimeter of rectangle with length {l} and breadth {b} is {rectangle.perimeter(l,b)}")
    
    #demonstrating cuboid module
    l = int(input("\nEnter length of cuboid : "))
    b = int(input("\nEnter breadth of cuboid : "))
    h = int(input("\nEnter heigth of cuboid : "))
    print(f"\nArea of cuboid with length {l}, breadth {b} and height {h} is {cuboid.surfaceArea(l,b,h)}")
    print(f"\nPerimeter of cuboid with length {l}, breadth {b} and height {h} is {cuboid.perimeter(l,b,h)}")
    
    #demonstrating sphere module
    r = int(input("\nEnter radius of sphere : "))
    print(f"\nArea of sphere with length {r} is {sphere.surfaceArea(r)}")
    print(f"\nPerimeter of sphere with length {r} is {sphere.perimeter(r)}")

main()
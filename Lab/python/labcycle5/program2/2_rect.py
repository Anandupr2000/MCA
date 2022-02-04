class rect:
    def __init__(self,l,b):
        self.a1=l
        self.a2=b

    def area(self):
        self.m=self.a1*self.a2

    def peri(self):
        self.n=2*(self.a1 + self.a2)

    def disp(self):
        print("\nArea of rectangle:", self.m)
        print("Perimeter of rectangle:", self.n)

    def compare(self,obj2):
        if self.m == obj2.m:
            print("\nAreas are equal")
        elif self.m > obj2.m:
            print(f"\nArea of first rectangle is greater than second")
        else:
            print("\nArea of second rectangle is greater than first")
def main():
    print("Enter values for first rectangle")
    l=int(input("Enter length:"))
    b=int(input("Enter breadth:"))
    obj1=rect(l,b)
    print("\nEnter values for second rectangle")
    l=int(input("Enter length:"))
    b=int(input("Enter breadth:"))
    obj2=rect(l,b)

    obj1.area()
    obj1.peri()
    obj2.area()
    obj2.peri()

    obj1.disp()
    obj2.disp()

    obj1.compare(obj2)


main()
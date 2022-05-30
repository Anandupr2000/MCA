abstract class Shape {
    abstract double area();
}

class Circle extends Shape {
    int r;

    Circle(int r) {
        this.r = r;
    }
    double area(){ return 3.14*r*r; }
}

class Square extends Shape {
    int s;

    Square(int s) {
        this.s = s;
    }
    double area(){ return s*s; }
}

class Rectangle extends Shape {
    int l, b;

    Rectangle(int l, int b) {
        this.l = l;
        this.b = b;
    }
    double area(){ return l*b; }
}

public class abstractClass {
    public static void main(String[] args) {
        Circle c = new Circle(6);
        Square sq = new Square(6);
        Rectangle r = new Rectangle(2, 3);
        System.out.println("Area of circle with raduis "+c.r+" = "+c.area());
        System.out.println("Area of square with one side "+sq.s+" = "+sq.area());
        System.out.println("Area of rectangle with length "+r.l+" and breadth "+r.b+" = "+r.area());
    }
}

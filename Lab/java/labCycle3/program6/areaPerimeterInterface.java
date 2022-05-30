import java.util.*;

interface shape {
    double area();

    double perimeter();
}

class Circle implements shape {
    int r;

    Circle(int r){ this.r = r; }

    public double area() {
        return 3.14 * r * r;
    }

    public double perimeter() {
        return 2 * 3.14 * r;
    }
}

class Rectangle implements shape {
    int l, b;

    Rectangle(int l, int b) {
        this.l = l;
        this.b = b;
    }

    public double area() {
        return l * b;
    }

    public double perimeter() {
        return 2*(l + b);
    }
}

public class areaPerimeterInterface {
    public static void main(String[] args) {
        Scanner inp = new Scanner(System.in);
        boolean flag = true;
        do {
            System.out.println("****** MENU ******");
            System.out.println("1 - Circle  ");
            System.out.println("2 - Rectangle  ");
            System.out.println("0 - Exit  ");
            System.out.print("Enter your choice :");
            int c = inp.nextInt();
            switch (c) {
                case 1: {
                    System.out.println("Enter radius : ");
                    Circle cr = new Circle(inp.nextInt());
                    System.out.println("Area of circle is "+cr.area());
                    System.out.println("Perimeter of circle is "+cr.perimeter());
                    break;
                }
                case 2: {
                    System.out.println("Enter length and breadth ");
                    Rectangle r = new Rectangle(inp.nextInt(),inp.nextInt());
                    System.out.println("Area of rectangle is "+r.area());
                    System.out.println("Perimeter of rectangle is "+r.perimeter());
                    break;
                }
                case 0: {
                    System.out.println("BYE...");
                    flag = false;
                    break;
                }
            }
        } while (flag);
        inp.close();
    }
}

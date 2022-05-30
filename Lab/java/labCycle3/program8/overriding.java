import java.util.*;

class rectangle {
        int l, b;

        rectangle() {
        }

        rectangle(int lngth, int brdth) {
                l = lngth;
                b = brdth;
        }

        double area() {
                return l * b;
        }
}

class circle extends rectangle {
        int r;

        circle() {}

        circle(int radius) {
                // super(l,b);
                r = radius;
        }

        double area() {
                return (3.14 * r * r);
        }
}

class square extends circle {
        int s;

        square(int side) {
                // super(r, l, b);
                s = side;
        }

        double area() {
                return (s * s);
        }
}

class overriding {
        public static void main(String ar[]) {
                int l, b, r, side;
                Scanner s = new Scanner(System.in);
                System.out.println("enter the length & breadth of the rectangle:");
                l = s.nextInt();
                b = s.nextInt();
                rectangle rt = new rectangle(l,b);
                System.out.println("Area: " + rt.area());
                System.out.println("enter the radius:");
                r = s.nextInt();
                circle c = new circle(r);
                System.out.println("Area: " + c.area());
                System.out.println("enter the side of the square:");
                side = s.nextInt();
                rectangle sc = new square(side);
                System.out.println("Area: " + sc.area());
                s.close();
        }

}
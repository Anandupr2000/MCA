abstract class Shape{
    abstract double calculateArea();
    // { return 0;};
}
class rectangle extends Shape{
    int l ,b;
    rectangle(int l,int b){
        this.l = l;
        this.b = b;
    }
    double calculateArea(){
        return l*b;
    }
}
class circle extends Shape{
    int r;
    circle(int r){
        this.r = r;
    }
    double calculateArea(){
        return (r*r*3.14);
    }
}
public class abstractProgram {
    public static void main(String[] args) {
        rectangle r = new rectangle(3, 4);
        circle c = new circle(4);
        System.out.println("Area of rectangle : "+r.calculateArea());
        System.out.println("Area of circle : "+c.calculateArea());
    }
}

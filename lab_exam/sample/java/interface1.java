interface a{
    int a=10;
    void display1();
}
interface b{
    void display2();
}
public class interface1 implements a,b{
    public void display1(){
        System.out.println("interface a "+"\nvalue of a = "+a);
    }
    public void display2(){
        System.out.println("interface b");
    }
    public static void main(String[] args) {
        interface1 i = new interface1();
        i.display1();
        i.display2();
    }
}

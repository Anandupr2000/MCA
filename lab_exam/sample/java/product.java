import java.util.Random;

interface bill{
    String shopName = "Baji kada";
    void calculate();
    void display();
}
public class product implements bill{
    public void display(){
        System.out.println("interface a "+"\nvalue of a = "+(new Random()).nextInt(25));
    }
    public void calculate(){
        System.out.println("interface b");
    }
    public static void main(String[] args) {
        product i = new product();
        i.display();
    }
}

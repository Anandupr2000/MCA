import java.util.*;

class product {
    String name;
    int quantity, price;

    void display() {
        System.out.println("Product name : " + name);
        System.out.println("quantity : " + quantity);
        System.out.println("price : " + price + "\n");
    }

    product compare(product p1, product p2) {
        if(p1.price<p2.price){
        if(price<p1.price) return this;
        else return p1;
        }
        else{
        if(price<p2.price) return this;
        else return p2;
        }
    }
}

public class _4program {
    public static void main(String[] args) {
        Scanner inp = new Scanner(System.in);
        // System.out.println("Enter no of products : ");
        product p[] = new product[3];
        for (int i = 0; i < 3; i++) {
            p[i] = new product();
            System.out.println("Enter details  : ");
            System.out.println("Enter name : ");
            p[i].name = inp.next();
            System.out.println("Enter quantity : ");
            p[i].quantity = inp.nextInt();
            System.out.println("Enter price : ");
            p[i].price = inp.nextInt();
        }
        p[0].display();
        // product temp = p[0].compare(p[1], p[2]);
        System.out.println("Lowest price product");
        (p[0].compare(p[1], p[2])).display();
        inp.close();
    }
}

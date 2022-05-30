interface amount {
    void calculate();
}

class product implements amount {
    static int netAmt,ordNo,date;
    int productId, quantity, unit_price, total;
    String name;

    product(int productId, String name, int quantity, int unit_price) {
        this.productId = productId;
        this.name = name;
        this.quantity = quantity;
        this.unit_price = unit_price;
        this.name = name;
    }

    public void calculate() {
        total = quantity * unit_price;
        netAmt += total;
    }
    void display(){
        System.out.println(productId+"           "+name+"           "+quantity+"           "+unit_price+"          "+total);
    }
}
public class Bill{
    public static void main(String[] args) {
        product.date = 22092000;
        product.ordNo = 9355456;
        product p1 = new product(101, "A", 2, 25);
        product p2 = new product(102, "B", 1, 100);
        p1.calculate();
        p2.calculate();
        System.out.println("Order No : "+product.ordNo);
        System.out.println("Date : "+product.date);
        System.out.println("\nProductId     Name    Quantity    unit_price     Total");
        System.out.println("________________________________________________________");
        p1.display();
        p2.display();
        System.out.println("________________________________________________________");
        System.out.println("\t\t\t\t\tNet.Amount   "+product.netAmt);
    }
}
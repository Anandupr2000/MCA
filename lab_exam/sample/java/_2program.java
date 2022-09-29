import java.util.Scanner;

public class _2program {
    static int l, b, area;

    public static void main(String a[]) {
        Scanner inp = new Scanner(System.in);
        System.out.println("Enter length and breadth of rectangle : ");
        l = inp.nextInt();
        b = inp.nextInt();
        area = l * b;
        System.out.println("Area : "+area);
        inp.close();
    }
}

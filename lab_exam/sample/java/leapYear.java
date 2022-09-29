import java.util.*;

public class leapYear {
    public static void main(String[] args) {
        int s, e;
        Scanner inp = new Scanner(System.in);
        System.out.println("Enter starting year : ");
        s = inp.nextInt();
        System.out.println("Enter ending year : ");
        e = inp.nextInt();
        System.out.println("Leap years between " + s + " and " + e + " are : ");
        for (int i = s; i <= e; i++) {
            if ((i % 100 != 0 || i % 400 == 0) && i % 4 == 0) {
                System.out.println(i);
            }
        }
    }
}

import java.util.*;
public class search {
    public static void main(String[] args) {
        String s,a = "asuhdfajihd-asdiodf=sdkfjhsdfh";
        Scanner inp = new Scanner(System.in);
        System.out.println("Enter the character to be searched : ");
        s = inp.next();
        if(a.contains(s)) System.out.println(s+" found at index "+a.indexOf(s));
        else System.out.println(s+" not found");
    }
}

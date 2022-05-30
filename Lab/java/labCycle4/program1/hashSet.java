import java.util.HashSet;
import java.util.Iterator;
import java.util.Scanner;

public class hashSet {
    public static void main(String[] args) {
        boolean flag = true;
        HashSet<Integer> hs = new HashSet<Integer>();
        Scanner inp = new Scanner(System.in);
        do{
            System.out.println("********* Menu *********");
            System.out.println("1 - Append an element");
            System.out.println("2 - Traverse");
            System.out.println("3 - Check empty");
            System.out.println("4 - Check size");
            System.out.println("0 - Exit");
            System.out.print("Enter your choice : ");
            int c = inp.nextInt();
            switch (c) {
                case 1: {
                    System.out.println("Enter element to be added : ");
                    hs.add(inp.nextInt());
                    // System.out.println(hs);
                    break;
                }
                case 2: {
                    Iterator<Integer> iterator = hs.iterator();
                    while(iterator.hasNext()) System.out.println(iterator.next());
                    break;
                }
                case 3: {
                    if(hs.isEmpty()) System.out.println("Hash set is empty");
                    else System.out.println("Hash set is not empty");
                    break;
                }
                case 4: {
                    System.out.println("Length of hash set is "+hs.size());
                    break;
                }
                case 0: {
                    System.out.println("BYE...");
                    flag = false;
                    break;
                }
            }
        }while(flag);
        inp.close();
    }
}

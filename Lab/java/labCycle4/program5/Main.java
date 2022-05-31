import java.util.*;
 
public class Main {
 
    public static void main(String []args) {
 
        Scanner sc =new Scanner(System.in);
        LinkedList<String> ll = new LinkedList<String>();
        System.out.println("Enter size of list:");
        int n=sc.nextInt();
        String elem;
        for(int i=0;i<n;i++){
            System.out.println("Enter "+(i+1)+" th element(String):");
            elem=sc.next();
            ll.add(elem);
                }
        System.out.println("Linked is is..."+ll);
        System.out.println("Deleting all elemants....");
        ll.clear();
        System.out.println("Linked list is empty...?"+ll.isEmpty());
        System.out.println("Linked list is..."+ll);
        sc.close();
 }
}
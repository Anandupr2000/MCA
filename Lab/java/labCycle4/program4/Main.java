import java.util.*;
public class Main {
 
    public static void main(String []args) {
 
        Scanner sc =new Scanner(System.in);
        ArrayList<String> al = new ArrayList<String>();
        System.out.println("Is List empty??  : "+al.isEmpty());
        System.out.println("Enter size of list: ");
        int n=sc.nextInt();
        String elem;
        for(int i=0;i<n;i++){
                  System.out.println("Enter "+(i+1)+" th String:");
                  elem=sc.next();
                  al.add(elem);
                }
        System.out.println("Is List empty??  : "+al.isEmpty());
        System.out.println("Array list: "+al);
        ListIterator<String> iterator = al.listIterator();
            System.out.println("\nUsing ListIterator:\n");
            while (iterator.hasNext())
                System.out.println("Value is : "+ iterator.next());
        System.out.println("Enter element to serach:");
        elem=sc.next();
        System.out.println(elem+" present at index: "+al.indexOf(elem));
        System.out.println("List Size: "+al.size());
        System.out.println("Enter element to remove:");
        elem=sc.next();
        if(al.contains(elem))
            al.remove(elem);
        System.out.println("Array list after deletion of "+elem+" is "+al);
        Object arr[]=al.toArray();
        System.out.println("Array formed from array list is : ");
        for(int j=0;j<arr.length;j++)
            System.out.println(arr[j]);
        
 }
}
import java.util.*;
 
public class Main {
 
    public static void main(String []args) {
 
        Scanner sc =new Scanner(System.in);
        Stack<Integer> st = new Stack<Integer>();
        System.out.println("Enter size of list:");
        int n=sc.nextInt();
        int elem;
        for(int i=0;i<n;i++){
            System.out.println("Enter "+(i+1)+" th element of stack:");
            elem=sc.nextInt();
            st.push(elem);
                }
        System.out.println("Stack is..."+st);
        Iterator value = st.iterator();
        System.out.println("The index values are: ");
        int ind;
        while (value.hasNext()) {
            ind=st.indexOf(value.next());
            System.out.print(ind+" ");
        }
        System.out.println("\nEnter position(index) of elemnt to delete: ");
        elem=sc.nextInt();
        st.remove(elem);
        System.out.println("Stack after element deletion..."+st);
 }
}
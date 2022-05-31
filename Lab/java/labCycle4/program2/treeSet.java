import java.util.*;
public class treeSet {
    public static void main(String[] args) {
        TreeSet<Integer> t = new TreeSet<Integer>();
        t.add(11);
        t.add(1);
        t.add(25);
        t.add(89);
        t.add(10);
        // System.out.println(t.descendingSet());
        // t = t.descendingSet();
        for(int i:t.descendingSet()){ 
                System.out.print(i+" ");
          }
        // System.out.println(t.contains(4));
        // System.out.println(t.ceiling(4));
    }
}

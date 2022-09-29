import java.util.*;

public class collect {
    public static void main(String[] args) {
        Map<Integer,String> map =  new HashMap<Integer,String>();
        map.put(1,"sjh");
        map.put(1,"abc");
        map.put(2,"lkj");
        System.out.println("Entries = > "+map.entrySet());
        System.out.print("\n");
        for(Map.Entry<Integer,String> m:map.entrySet()){
            System.out.print(" "+m);
        }
        System.out.print("\n "+map.keySet());  
        System.out.print("\n");
        for(int m:map.keySet()){
            System.out.print(" "+map.get(m));
        }
        ArrayList<Integer> al = new ArrayList<Integer>(1);
        al.add(3);
        al.remove(3);
        al.clear();
        al.contains(2);
    }
}

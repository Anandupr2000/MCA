import java.util.*;

public class sortString {
    public static void main(String[] args) {
        int i,n;
        Scanner inp = new Scanner(System.in);
        System.out.print("\nEnter limit : ");
        n =inp.nextInt();
        String str[] = new String[n];
        System.out.print("\nEnter array : ");
        for( i=0;i<n;i++) str[i] = inp.next();
        System.out.print("\nArray is : ");
        for(String x:str)
            System.out.print(x+",");
        // Arrays.sort(str);
        for(i=0;i<n;i++){
            for(int j=0;j<n;j++)
                if(str[i].compareTo(str[j])<0){
                    String temp = str[i];
                    str[i] = str[j];
                    str[j] = temp;
                }
        }
        System.out.print("\nSorted : ");
        for(String x:str)
            System.out.print(x+",");
        inp.close();
    }   
}

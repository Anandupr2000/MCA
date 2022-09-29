import java.io.BufferedReader; 
import java.io.InputStreamReader;
import java.io.IOException;
class complexNo{
    int r,i;
    complexNo(){}
    complexNo(int i,int r){
        this.i = i;
        this.r = r;
    }
    complexNo add(complexNo c1,complexNo c2){
        complexNo temp = new complexNo();
        temp.i = c1.i + c2.i;
        temp.r = c1.r + c2.r;
        return temp;
    }
}
public class complex {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("\nEnter real and imaginary part of first complex no : ");
        // int real = br.read();
        // int imaginary = br.read();
        complexNo c1 = new complexNo(Integer.parseInt(br.readLine()),Integer.parseInt(br.readLine()));
        System.out.print("\nEnter real and imaginary part of first complex no : ");

        complexNo c2 = new complexNo(Integer.parseInt(br.readLine()),Integer.parseInt(br.readLine()));
        complexNo temp = c1.add(c1,c2);
        System.out.print("\n"+ c1.r+"+"+c1.i+"i");
        System.out.print( " + ");
        System.out.print( c2.r+"+"+c2.i+"i");
        System.out.print( " gives ");
        System.out.print( temp.r+"+"+temp.i+"i");
    }
} 
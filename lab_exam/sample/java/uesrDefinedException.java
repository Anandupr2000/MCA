import java.util.*;

class userException extends Exception {
    public userException(String msg) {
        super(msg);
        // super.
    }
}

public class uesrDefinedException {
    public static void main(String[] args) {
        Random r = new Random(35);
        // int a = r.nextInt();
        int a = 15;
        try{
            System.out.print("User defined exception");
            if(a<10) throw new userException("Number less than 10"); 
            else System.out.println("No error");
        }catch(Exception e){
            System.out.print(e);
            e.getMessage();
        }
    }
}

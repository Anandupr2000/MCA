import java.util.Scanner;

public class _3program {
    // static boolean check(int num) {
        // boolean flag =true;
        // if (num < 2) {
        //     return false;
        // } else {
        //     for (int i = 2; i < num / 2; i++) {
        //         if (num % i == 0){
        //             flag = false;
        //             break;
        //         }    
        //     }
        // }
        // return flag;
    // }

    public static void main(String[] args) {
        Scanner inp = new Scanner(System.in);
        System.out.println("Enter a number : ");
        int num = inp.nextInt();
        if(num%2==0) System.out.println(num+" is even");
        else System.out.println(num+" is odd");
        inp.close();
    }
}

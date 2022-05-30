import java.util.*;
class figure{
        double findArea(float r){return r*r*3.12;}
        int findArea(int a){return a*a;}
        int findArea(int l,int b){return l*b;}
}
class main1{
        public static void main(String a[]){
                float r;
                int l,b;
                Scanner inp = new Scanner(System.in);
                figure obj = new figure();
                System.out.println("\nEnter length of radius of circle : ");    
                r = inp.nextFloat();    
                System.out.println("Area of circle with radius "+r+" = "+obj.findArea(r));
                System.out.println("\nEnter length of one side of square : ");  
                l = inp.nextInt();      
                System.out.println("Area of square with one side length "+l+" = "+obj.findArea(l));
                System.out.println("\nEnter length of rectangle : ");  
                l=inp.nextInt();
                System.out.println("\nEnter breadth of rectangle : ");  
                b= inp.nextInt();      
                System.out.println("Area of square with length "+l+" and breadth "+b +" = "+obj.findArea(l,b));
        }
}

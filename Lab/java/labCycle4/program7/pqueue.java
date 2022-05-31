import java.util.*;
public class pqueue{
	public static void main(String args[]){
		int n,element;
		PriorityQueue<Integer> numbers=new PriorityQueue<Integer>();
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the limit of Queue:");
		n=sc.nextInt();
		for(int i=0;i<n;i++)
		{
			System.out.println("Enter the "+(i+1)+"th Element to the Queue:");
			element=sc.nextInt();
			numbers.add(element);
		}
		System.out.println("Elements in the Queue:");
		for(int i:numbers){
			System.out.println(i);
		}
		sc.close();
	}


}
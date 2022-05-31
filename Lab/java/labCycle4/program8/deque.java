import java.util.*;
public class deque{
	public static void main(String args[]){
		Deque<String> dq=new LinkedList<String>();
		dq.addFirst("Head Element");
		dq.add("middle Element1");
		dq.add("middle Element2");
		dq.add("middle Element3");
		dq.add("middle Element4");
		dq.addLast("Last Element");
		System.out.println("Deque Elements:");
		Iterator i=dq.iterator();
		while(i.hasNext())
		{
			System.out.println("\t"+i.next());
		}
		System.out.println("Removing Fist Element");
		dq.removeFirst();
		System.out.println("Removing Last Element");
		dq.removeLast();
		System.out.println("After Removing First And Last Element : "+dq);
		dq.remove("middle Element2");
		System.out.println("After Removing middle Element2 : "+dq);
	}

}

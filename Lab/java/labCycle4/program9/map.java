import java.util.*;
public class map{
	public static void main(String args[]){
	Map<String,Integer> height=new HashMap<String,Integer>();
	//Adding
	height.put("Arun",178);
	height.put("Anu",167);
	height.put("Joel",188);
	height.put("Deepak",180);
	for(Map.Entry<String,Integer> e:height.entrySet())
	{
		System.out.println(e.getKey()+" : "+e.getValue());
	}
	//changing
	height.put("Joel",190);
	System.out.println("updated map"+height);
	//removing
	height.remove("Anu");
	System.out.println("After Removing Anu:"+height);
}
}
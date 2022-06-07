
import java.util.*;
import java.util.stream.*;
public class main{
	public static Map<Integer,String>convertToTreeMap(Map<String,String>hashMap)
	{
		Map<Integer,String> treeMap= new TreeMap<>();
		// System.out.print(hashMap.entrySet());
		for(Map.Entry<String,String> e:hashMap.entrySet()){
			// System.out.println(e);
			treeMap.put(Integer.parseInt(e.getKey()),e.getValue());
		}
		return treeMap;
	}
	public static void main(String args[])
	{
		Map<String,String> hashMap=new HashMap<>();
		hashMap.put("101","Jayaraj");
		hashMap.put("104","Gokul");
		hashMap.put("107","Anandu");
		System.out.println("HashMap:"+hashMap);
		Map<Integer,String> treeMap=convertToTreeMap(hashMap);
		System.out.println("TreeMap:"+treeMap);
	}
}
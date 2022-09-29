program1
import java.util.HashSet;
import java.util.Iterator;
import java.util.Scanner;

public class hashSet {
    public static void main(String[] args) {
        boolean flag = true;
        HashSet<Integer> hs = new HashSet<Integer>();
        Scanner inp = new Scanner(System.in);
        do{
            System.out.println("********* Menu *********");
            System.out.println("1 - Append an element");
            System.out.println("2 - Traverse");
            System.out.println("3 - Check empty");
            System.out.println("4 - Check size");
            System.out.println("0 - Exit");
            System.out.print("Enter your choice : ");
            int c = inp.nextInt();
            switch (c) {
                case 1: {
                    System.out.println("Enter element to be added : ");
                    hs.add(inp.nextInt());
                    // System.out.println(hs);
                    break;
                }
                case 2: {
                    Iterator<Integer> iterator = hs.iterator();
                    while(iterator.hasNext()) System.out.println(iterator.next());
                    break;
                }
                case 3: {
                    if(hs.isEmpty()) System.out.println("Hash set is empty");
                    else System.out.println("Hash set is not empty");
                    break;
                }
                case 4: {
                    System.out.println("Length of hash set is "+hs.size());
                    break;
                }
                case 0: {
                    System.out.println("BYE...");
                    flag = false;
                    break;
                }
            }
        }while(flag);
        inp.close();
    }
}

algo:
Step 1 : Start
Step 2 : Declare a HashSet collection hashSet with Integer as element type
Step 3 : Perform step 4,5,6 & 7 using menu
Step 4 : Read an element and add to collection using hashSet.add()
Step 5 : for Integer i in hashSet print i
Step 6 : Check emptiness of hashSet using hashSet.isEmpty() 
Step 7 : Print length of hashSet using hashSet.size() 
Step 8 : Stop


program2
import java.util.*;
class Treesetprgrm{
    public static void main(String args[]){
        TreeSet set=new TreeSet();
        set.add("notebook");
        set.add("bag");
        set.add("calculator");
        set.add("calculator");//treeset contains only unique elements
        System.out.println("Set elements are: "+ set);
        System.out.println();
        System.out.println("Traversing element through Iterator in descending order:
        ");
        Iterator i=set.descendingIterator();
        while(i.hasNext()){
        System.out.println(i.next());
        }
    }
}
algo

Step 1 : Start
Step 2 : Declare a TreeSet<Integer> collection object treeSet
Step 3 : Add some integer to treeSet using add() fn
Step 4 : for int i in treeSet.descendingSet() perform step5
Step 5 : Print value of i
Step 6 : Stop


program3

import java.util.*;
class Linkedhashsetprgrm{
public static void main(String args[]){
LinkedHashSet<String> set=new LinkedHashSet<>();
set.add("Hamlet");
set.add("Macbeth");
set.add("Othello");
set.add("Othello");//linkedhashset contains only unique elements
System.out.println("Elements: " + set);
}
}
Step 1 : Start
Step 2 : Declare a LinkedHashSet linkedHashSet with String as object type
Step 3 : Add Strings to linkedHashSet using add() fn
Step 4 : Display linkedHashSet
Step 5 : Stop

program4
Step 1 : Start
Step 2 : Declare a ArrayList names with with String as object type
Step 3 : Add some String values to "names" using add() fn
Step 4 : Display a menu to perform the following steps 5,6,7,8 & 9
Step 5 : Read index value and name from user, then add to names using add(index,name)
Step 6 : Read name from user and print its position using indexOf(name) fn
Step 7 : Print the size of ArrayList "names" using size() fn
Step 8 : Check emptiness of names using isEmpty() 
Step 9 : Remove name in names by reading index value from user, using remove(index)
Step 10 : Stop

program5
Step 1 : Start
Step 2 : Define a Class linkedlist prgrm
Step 3 : Create an Arrayhist of string type called "fruits".
Step 4 : Add elements into Arraylist using add() method.
Step 5 : Declare a linkedhist ("fruit-list) object with parameter 'fruits' 
Step 6 : Display the Linkedlist elements
Step 7 : Delete all elements in linkedlist using clear() method.
Step 8 : Display the linked list after removing all elements
Step 9 : Stop

program6
Step 1 : Start
Step 2 : Define a Create class Stackprym & stack object "numbers"
Step 3 : Add elements into stack object using push().
Step 4 : Print the shot elements 
Step 5 : Accept position of object to be deleted from user
Step 6 : use remove() method of stack to remove element of (position -1).
Step 7 : Display the removed element
Step 8 : Print the list of elements after deletion
Step 9 : Stop

program7
Step 1 : Start
Step 2 : Define a class PriorityQueue prgrm
Step 3 : Create an object 'art' of Priority Queue of string type
Step 4 : Add elements into priority queue using add() method.
Step 5 : Define the iterator to i for priority queue to iterate through the prionty queue & display its elements.
Step 6 : Stop

program8
Step 1 : Start
Step 2 : Declare a object deque of Deque type with String type element
Step 3 : Assign an instance of LinkedList collection with String type element to deque
Step 4 : Perform the following steps 5,6,7,8,9,10,11 & 12 using menu
Step 5 : Read an String from user and add it to deque uing add() fn 
Step 6 : Read an String from user and add at begining of deque uing addFirst() fn 
Step 7 : Read an String from user and add at end of deque uing addLast() fn 
Step 8 : Read an String from user and perform push operation using push() fn 
Step 9 : Display elements of deque using iterator
Step 10 : Display elements of deque after performing pop operation on deque using pop() fn
Step 11 : Display elements of deque after removing first element of deque using removeFirst() fn
Step 12 : Display elements of deque after removing last element of deque using removeLast() fn
Step 13 : Stop

program9
Step 1 : Start
Step 2 : Declare a object hashMap of HashMap type with key-value type as Integer-String
Step 3 : Add some key-value pair to hashMap using put(key,value) fn
Step 4 : Display the elements of hashMap to show intial state.
Step 5 : Perform the following steps using menu
Step 6 : Read key and value from user and add them to hashMap using put(key,value) fn
Step 7 : Read key for element to be deleted and remove it from hashMap using remove(key) fn
Step 8 : Perform the following to update hashMap - 
        i) Read key of element to be replaced and new value
        ii) add them to hashMap using replace(key,value) fn
Step 9 : Stop

program10
Step 1 : Start
Step 2 : Declare a object hashMap of type HashMap collection with key-value type as String 
Step 3 : Add some key-value pairs to  hashMap using put(key,value)
Step 4 : Declare a object treeMap of type TreeMap collection with key-value type as String
Step 5 : Convert hashMap to TreeMap by add all elements of hashMap to treeMap using putAll()fn
Step 6 : Display the TreeMap
Step 7 : Stop
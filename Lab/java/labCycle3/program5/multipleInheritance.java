import java.util.*;

interface student {

    /**
     * data members in interface are public,static and final
     * member functions are public and abstract
     */
    String sname = "Anandu", gender = "Male";
    int mark = 70;
}

interface sports {
    String category = "Running";
    int place = 1, score = 20;
}

class Result implements student, sports {
    int total = score+mark;    

    public void display() {
        System.out.println("Name : " + sname);
        System.out.println("Gender : " + gender);
        System.out.println("Marks had : " + mark);
        System.out.println("Sports category : " + category);
        System.out.println("Place obtained : " + place);
        System.out.println("Marks rewarded : " + score);
        System.out.println("\nTotal Marks:" + total);
    }
}

public class multipleInheritance {
    public static void main(String[] args) {
        Result r = new Result();
        System.out.println("\n*********** Details ***********");
        r.display();
    }
}

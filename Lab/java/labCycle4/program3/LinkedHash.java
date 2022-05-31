import java.util.*;

class book {
    int id;
    String title, author;

    book(int id, String title, String author) {
        this.author = author;
        this.id = id;
        this.title = title;
    }
}

public class LinkedHash {
    public static void main(String[] args) {
        LinkedHashSet<book> l = new LinkedHashSet<book>();
        l.add(new book(101, "Let us C", "BPB"));
        l.add(new book(102, "Alchemist", "Paulo Coelo"));
        l.add(new book(103, "Wings Of Fire", "APJ Abdul Kalam"));
        for (book b : l)
            System.out.println(b.id + "   " + b.title + "     " + b.author);
    }
}

import java.util.*;

class Publisher {
    String name;
    int date;

    Publisher(String name, int date) {
        this.date = date;
        this.name = name;
    }
}

class Book extends Publisher {
    String title, author;
    int no_of_pages;

    Book(String title, String author, int no_of_pages, String name, int date) {
        super(name, date);
        this.author = author;
        // this.name = name;
        // this.date = date;
        this.title = title;
        this.no_of_pages = no_of_pages;
    }

    void displayDetails() {
        System.out.println("Title : " + title);
        System.out.println("Author : " + author);
        System.out.println("Number of pages : " + no_of_pages);
        System.out.println("Publisher name : " + name);
        System.out.println("Publish date : " + date);
    }
}

class Fiction extends Book {
    static String type = "Fiction";

    Fiction(String title, String author, int no_of_pages, String name, int date) {
        super(title, author, no_of_pages, name, date);
    }

    void display() {
        System.out.println("Book type : " + type);
        displayDetails();
    }
}

class Literature extends Book {
    static String type = "Literature";

    Literature(String title, String author, int no_of_pages, String name, int date) {
        super(title, author, no_of_pages, name, date);
    }

    void display() {
        System.out.println("Book type : " + type);
        displayDetails();
    }
}

public class heriarchialInheritance {
    static String title, author, pName;
    static int no_of_pages, date;
    static Scanner inp = new Scanner(System.in);

    static void readData() {
        System.out.println("Enter the book title : ");
        title = inp.next();
        System.out.println("Enter the book author : ");
        author = inp.next();
        System.out.println("Enter the book publisher name : ");
        pName = inp.next();
        System.out.println("Enter the number of pages in book : ");
        no_of_pages = inp.nextInt();
        System.out.println("Enter the book publish date : ");
        date = inp.nextInt();
    }

    public static void main(String[] args) {
        System.out.println("************* Enter book details of fiction type *************");
        readData();
        Fiction f = new Fiction(title, author, no_of_pages, pName, date);
        System.out.println("************* Enter book details of literature type *************");
        readData();
        Literature l = new Literature(title, author, no_of_pages, pName, date);
        System.out.println("************* Book details of fiction type *************");
        f.display();
        System.out.println("************* Book details of literature type *************");
        l.display();
        inp.close();
    }
}

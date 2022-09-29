class CPU_details {
    int price;

    class processor {
        String manufacturer = "intel";
        int no_of_cores = 20;
    }

    static class RAM {
        int memory = 4096;
        String manufacturer = "Crucial";
    }
}

public class CPU{
    public static void main(String[] args) {
        CPU_details details = new CPU_details();
        CPU_details.processor p = new CPU_details().new processor();
        CPU_details.RAM r = new CPU_details.RAM();
        System.out.println("Details");
        System.out.println("Processor manufacturer : "+p.manufacturer);
        System.out.println("price = "+details.price);
        System.out.println("no_of_cores = "+p.no_of_cores);
        System.out.println("Ram capacity = "+r.memory);
        System.out.println("Ram manufacturer = "+r.manufacturer);
    }
}
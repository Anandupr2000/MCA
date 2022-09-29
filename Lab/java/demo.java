import java.io.*;
class demo{
    public static void main(String[] args) throws IOException {
        // BufferedReader br = new BufferedReader(new FileReader("./labCycle4/algo.txt.java"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while (!br.readLine().equals("stop"))System.out.println(br.readLine());
        // String.parseInt("q");
    }
}
public class stringManip {
    public static void main(String[] args) {
        StringBuffer sb  = new StringBuffer("Anandu");
        System.out.println("Before appending => "+sb);
        System.out.println("String size => "+sb.capacity());
        sb.append(" P R");
        System.out.println("After appending => "+sb);
        System.out.println("String size => "+sb.capacity());
        System.out.println("3rd character is "+sb.charAt(2));
    }
}

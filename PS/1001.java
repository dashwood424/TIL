import java.util.*;
public class Main{
    public static void main(String[] args){
        int a;
        int b;
        Scanner scanner=new Scanner(System.in);
        a=scanner.nextInt();
        b=scanner.nextInt();
        if(a>0 && b<10) {
            System.out.println(a-b);
        }
    }
}
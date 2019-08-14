import java.util.*;
public class Main {
    public static void main(String[] args){
        int a;
        int b;
        Scanner sc=new Scanner(System.in);
        a=sc.nextInt();
        b=sc.nextInt();
        if(a>0 && b>0 && b<10){
            System.out.print(a+b);
        } 
    }
}
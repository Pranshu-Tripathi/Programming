import java.util.Scanner;

public class expression {


    int a, b, c;


    public expression(int A,int B,int C){
        // constructor of class
        this.a  = A;
        this.b = B;
        this.c = C;
    }

    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);

        expression e = new expression(scanner.nextInt(), scanner.nextInt(), scanner.nextInt());
        scanner.close();
        if(e.a == 1 && e.b == 1 && e.c == 1){
            System.out.println(3);
        }else if(e.a == 1 && e.b == 1){
            System.out.println((e.a+e.b)*e.c);
        }else if(e.b == 1 && e.c == 1){
            System.out.println(e.a*(e.b+e.c));
        }else if(e.a == 1 && e.c ==1){
            System.out.println(e.a + e.b + e.c);
        }else if(e.a == 1){
            System.out.println((e.a+e.b)*e.c);
        }else if (e.b == 1){
            System.out.println((min(e.a, e.c)+e.b)*max(e.a, e.c));
        }else if(e.c == 1){
            System.out.println(e.a*(e.b+e.c));
        }else{
            System.out.println(e.a * e.b * e.c);
        }
    }

    private static int max(int a1,int a2){
        if(a1 > a2){
            return a1;
        }
        else{
            return a2;
        }
    }
    private static int min(int a1,int a2){
        if(a1 > a2){
            return a2;
        }
        else{
            return a1;
        }
    }

    
}
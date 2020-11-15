import java.util.Scanner;

public class theatre_square {

    long N,M,A;
    
    public theatre_square(long n,long m, long a){
        this.N = n;
        this.M = m;
        this.A = a; 
    }

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        theatre_square th_sq = new theatre_square(scanner.nextLong(), scanner.nextLong(), scanner.nextLong());
        scanner.close();
        long req = 0;
        long req1 = 0; 
        if(th_sq.N % th_sq.A != 0){
            req = th_sq.N/th_sq.A + 1;
        }else{
            req = th_sq.N/th_sq.A;
        }

        if(th_sq.M % th_sq.A != 0){
            req1 = th_sq.M/th_sq.A + 1;
        }else{
            req1 = th_sq.M/th_sq.A;
        }

        System.out.println(req1 * req);
    }
    
}
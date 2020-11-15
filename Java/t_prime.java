import java.util.Scanner;

public class t_prime {
    
    boolean[] primes = new boolean[1000001];
    public t_prime(boolean[] a){
        this.primes = a;
    }

    public static void main(String[] args){
        // precomputing the prime numbers.
        boolean[] a = new boolean[1000001];
        for(int i = 2 ; i <= 1000000; i++){
            a[i] = true;
        }
        a[0] = false;
        a[1] = false;
        
        for(int i = 2; i*i <= 1000000; i++){
            if(a[i] == true){
                for(int j = i*i; j <= 1000000; j+=i){
                    a[j] = false;
                }
            }
        }

        t_prime p = new t_prime(a);

        Scanner scanner = new Scanner(System.in);

        int testcase = scanner.nextInt();

        while(testcase > 0){

            long test = scanner.nextLong();
            double sqrt =  Math.sqrt(Long.valueOf(test).doubleValue());
            if((sqrt - (int) sqrt) == 0){
                if(p.primes[(int)sqrt]){
                    System.out.println("YES");
                }else{
                    System.out.println("NO");
                }
            }else{
                System.out.println("NO");
            } 
            testcase--;
        }
        scanner.close();


    }
}


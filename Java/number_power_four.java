import java.util.Scanner;

public class number_power_four {


    public number_power_four(){

    }

    public static int isNUmberPowFour(Long n){

        // count number of set bits
        long x = n & n-1;
        if(n > 0 && x == 0){
            int count = 0;
            while(n > 1){
                n >>= 1;                   // same as sending 16 to 8 i.e set bit shifting
                count++;
            }

            if(count % 2 == 0){
                return 1;
            }else{
                return 0;
            }

        }else{
            return 0;
        } 
    }

    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        int test = scanner.nextInt();
        while(test > 0){
            Long N = scanner.nextLong();
            int ans = isNUmberPowFour(N);
            if(ans == 0){
                System.out.println("NO");
            }else{
                System.out.println("YES");
            }
            test--;
        }

        scanner.close();
    }
    
}
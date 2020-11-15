import java.util.Scanner;

public class iq_test{

    public static void main(final String[] args) {

        final Scanner scanner = new Scanner(System.in);
        final int N = scanner.nextInt();
        final int[] arr = new int[N];
        int last_odd = 0;
        int last_even = 0;
        int odd_fre = 0;
        int even_fre = 0;
        for (int i = 0; i < N; ++i) {
            arr[i] = scanner.nextInt();
            if(arr[i] % 2 == 0){
                even_fre++;
                last_even = i;
            }else{
                odd_fre++;
                last_odd = i;
            }
        }
        scanner.close();
        int ans = 0;
        if(even_fre == 1){
            ans = last_even+1;
        }else if(odd_fre == 1){
            ans = last_odd+1;
        } 
        System.out.println(ans);
    }

}
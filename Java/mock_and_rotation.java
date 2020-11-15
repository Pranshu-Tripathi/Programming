import java.util.Scanner;

public class mock_and_rotation {

    public mock_and_rotation(){
        // empty constructor
    }

    public static void main(String[] args){
        
        
        Scanner scanner = new Scanner(System.in);
        int test = scanner.nextInt();
        while(test > 0){
            int N = scanner.nextInt();
            int k = scanner.nextInt();
    
            int[] arr_ans = new int[N];
            int[] arr = new int[N];
            for(int i = 0; i < N ; i++){
                arr[i] = scanner.nextInt();
                arr_ans[(i+k)%(N)] = arr[i];
            }
            
    
            for(int i = 0 ; i < N ; i++){
                System.out.print(arr_ans[i]+" ");
            }
            
            test--;
        }

        scanner.close();
    }    
}
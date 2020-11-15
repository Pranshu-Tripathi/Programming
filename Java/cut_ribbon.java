import java.util.Scanner;

public class cut_ribbon {

    public cut_ribbon(){
        // empty constructor
    }

    public static void main(String[] args){
        int N,A,B,C;
        Scanner sca = new Scanner(System.in);
        N = sca.nextInt();
        A = sca.nextInt();
        B = sca.nextInt();
        C = sca.nextInt();
        sca.close();

        int[] dp = new int[N + 1];
        dp[0] = 0;

        System.out.println(implement(dp,N,A,B,C));

    }

    private static int implement(int[] dp,int N,int A, int B, int C){
        
        for(int i = 1; i <= N ; ++i){
            int x=-1,y=-1,z=-1;

            if(i >= A){
                x = dp[i-A];
            }

            if(i >= B){
                y = dp[i-B];
            }

            if(i >= C){
                z = dp[i-C];
            }

            if(x == -1 && y == -1 && z == -1){
                dp[i] = -1;
            }else{
                dp[i] = max(z,max(x,y))+1;   
            }
        }
        return dp[N];
    }

    private static int max(int a,int b){
        if(a> b){
            return a;
        }else{
            return b;
        }
    }
}
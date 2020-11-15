import java.util.ArrayList;
import java.util.Scanner;

public class LCMProblem
{

    long left;
    long right;

    public LCMProblem(long l, long r)
    {
        this.left = l;
        this.right = r;
    }

    public static void main(String[] args)
    {

        Scanner scanner = new Scanner(System.in);
        int test = scanner.nextInt();

        for(int i = 0 ; i < test ; i ++)
        {
            long l = scanner.nextLong();
            long r = scanner.nextLong();

            LCMProblem LCM = new LCMProblem(l, r);

            ArrayList<Long> ans = new ArrayList<Long>();
            ans = solve(LCM);
            for(int j = 0 ;  j < ans.size(); j++)
            {
                System.out.print(ans.get(i)+" ");
            }
            System.out.print("\n");
        }
        scanner.close();
    }

    private static ArrayList<Long> solve(LCMProblem l)
    {
        ArrayList<Long> ans = new ArrayList<Long>();
        if(l.left * 2 < l.right){
            ans.add(l.left);
            ans.add(l.left*2);
        }else{
            ans.add((long) -1);
        }

        return ans;
    }
}
import java.util.ArrayList;
import java.util.Scanner;

public class DiceCombination
{
    int mod;
    ArrayList<Integer> fib;
    ArrayList<Boolean> vis;
    
    public DiceCombination()
    {
        this.mod = 1000000007;
        this.fib = new ArrayList<>(1000001);
        this.vis = new ArrayList<>(1000001);
    }

    public static void init(DiceCombination d)
    {
        for(int i = 0  ; i < d.fib.size() ; i++)
        {
            d.fib.set(i,0);
            d.vis.set(i, false);
        }
    }

    public static int dice(int n,DiceCombination d)
    {
        if(n < 0)
        {
            return 0;
        }
        else if(d.vis.get(n))
        {
            return d.fib.get(n);
        }
        else
        {
            int x = dice(n-1,d) + dice(n-2,d) + dice(n-3,d) + dice(n-4,d) + dice(n-5,d) + dice(n-6,d) +1;
            d.fib.set(n, x);
            d.vis.set(n, true);
            return d.fib.get(n);
        }
    }

    public static void main(String[] args)
    {
        DiceCombination d = new DiceCombination();
        init(d);
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.close();
        System.out.println(dice(n, d));
    }

}

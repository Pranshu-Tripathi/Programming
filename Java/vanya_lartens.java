import java.util.Scanner;
import java.util.Arrays;


public class vanya_lartens {

    int lartens;
    long street;
    long start_boundary;
    long end_boundary; 
    long[] positions = new long[0];

    public vanya_lartens(final int N, final long l, final long[] positions) {
        this.lartens = N;
        this.street = l;
        this.end_boundary = 0;
        this.start_boundary = 0;
        this.positions = positions;
    }

    public static void main(final String[] args) {
        int N;
        long l;
        final Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();
        l = scanner.nextLong();
        final long[] positions = new long[N];
        for (int i = 0; i < N; ++i) {
            positions[i] = scanner.nextLong();
        }
        Arrays.sort(positions);
        scanner.close();

        final vanya_lartens V = new vanya_lartens(N, l, positions);
        V.end_boundary = V.street - V.positions[V.lartens - 1];
        V.start_boundary = V.positions[0];

        long min = Long.MIN_VALUE;
        for (int i = 1; i < V.lartens; i++) {
            if (min < (V.positions[i] - V.positions[i - 1])) {
                min = (V.positions[i] - V.positions[i - 1]);
            }
        }

        Double ans;
        Double minD = Long.valueOf(min).doubleValue() / 2.0;
        Double start_bound = Long.valueOf(V.start_boundary).doubleValue();
        Double end_boundary = Long.valueOf(V.end_boundary).doubleValue();

        ans = max(minD,max(start_bound,end_boundary));
        System.out.println(ans);
    }

    private static Double max(final Double a1, final Double a2) {
        if(a1 > a2){
            return a1;
            
        }else{
            return a2;
        }
    }

}
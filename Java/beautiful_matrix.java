
import java.util.Scanner;


public class beautiful_matrix {


    int[][] matrix = new int[5][5];
    int position_x;
    int position_y;

    public beautiful_matrix(int[][] ma, int p , int y){
        // constructor
        this.matrix = ma;
        this.position_x = p;
        this.position_y = y;
    }

    public static void main(String[] args){
        int[][] ma = new int[5][5];
        int x = 0,y = 0;
        Scanner scanner = new Scanner(System.in);
        for(int i = 0; i < 5; ++i){
            for(int j =0; j < 5; ++j){
                ma[i][j] = scanner.nextInt();
                if(ma[i][j] == 1){
                    x = i+1;
                    y = j+1;
                }
            }
        }
        scanner.close();
        beautiful_matrix B = new beautiful_matrix(ma,x,y);
        int ans = 0;
        ans = abs(B.position_x - 3)+abs(B.position_y - 3);
        System.out.println(ans);
    }

    private static int abs(int i) {
        if(i > 0){
            return i;
        }
        else{
            return -i;
        }
    }
    
}
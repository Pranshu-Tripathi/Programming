import java.util.Scanner;

public class even_odds {

    public even_odds(){
        //constructor
    }

    public static void main(String[] args){
        
        Scanner scanner = new Scanner(System.in);
        Long N = scanner.nextLong();
        Long K = scanner.nextLong();
        scanner.close();

        Long loop_end;

        if(N % 2 == 0){
            loop_end = N/2;
        }else{
            loop_end = N/2+1;
        }

        if(K > loop_end){
            System.out.println((K-loop_end)*2);
        }else{
            System.out.println((K)*2-1);
        }

    }
    
}
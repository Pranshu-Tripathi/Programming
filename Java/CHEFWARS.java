import java.util.Scanner;

public class CHEFWARS{

    public CHEFWARS(){
        // empty constructor
    }

    public static void main(String[] args){

        Scanner scanner = new Scanner(System.in);

        int Test = scanner.nextInt();

        for(int i = 0; i < Test ; ++i){

            int H = scanner.nextInt();
            int P = scanner.nextInt();

            while(P > 0 && H > 0){
                H -= P;
                P /= 2;
            }

            if(H > 0){
                System.out.println(0);
            }else{
                System.out.println(1);
            }

        }


        scanner.close();

    }

}
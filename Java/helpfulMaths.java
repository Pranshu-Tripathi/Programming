import java.util.Arrays;
import java.util.Scanner;

public class helpfulMaths{


    public helpfulMaths(){
        // empty constructor;
    }

    public static void main(String[] args){
        solve();
    }

    private static void solve() {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        scanner.close();

        int len = s.length();

        if(len > 1){
            String[] splStrings = s.split("\\+",0);

            int[] arrayList = new int[splStrings.length];

            for(int i = 0 ; i < splStrings.length ; i ++ ){
                arrayList[i] = Integer.parseInt(splStrings[i]);
            }

            Arrays.sort(arrayList);

            for(int i = 0; i < arrayList.length-1; i ++){
                System.out.print(Integer.toString(arrayList[i])+"+");
            }
            System.out.print(Integer.toString(arrayList[arrayList.length-1]));
        }else{
            System.out.println(s);
        }
    }
}
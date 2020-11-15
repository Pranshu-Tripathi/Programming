import java.util.HashMap;
import java.util.Scanner;

public class registration_sys{
    HashMap<String,Integer> map = new HashMap<>();
    public registration_sys(){
        // empty constructor
    }

    public static void main(String[] args){
        int inputs = 0;
        registration_sys r = new registration_sys();
        Scanner scanner = new Scanner(System.in);
        
        inputs = scanner.nextInt();
        
        for(int i = 0 ; i < inputs ; ++i){
            String username = scanner.next();
            if(r.map.containsKey(username)){
                int lastValue = r.map.get(username);
                String outString = username + Integer.toString(lastValue+1);
                r.map.replace(username, lastValue,lastValue+1);
                System.out.println(outString);
            }else{
                r.map.put(username, 0);
                System.out.println("OK");
            }
        }
        scanner.close();
    }
}
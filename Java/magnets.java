import java.util.Scanner;

public class magnets {



    public magnets(){
        // constructor
    }


    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        
        int size = scanner.nextInt();
        int group = 1;
        String[] magn = new String[size];

        magn[0] = scanner.next();

        size-=1;
        int i = 1;
        while(size > 0){
            
            magn[i] = scanner.next();

            if(!magn[i].equals(magn[i-1])){
                group++;
            }
            size--;
            i++;
        }
        scanner.close();

        System.out.println(group);
    }
    
}
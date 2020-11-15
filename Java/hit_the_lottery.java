import java.util.Scanner;

public class hit_the_lottery {

    public hit_the_lottery(){

    }

    public static void main(String[] args){
        long money;
        Scanner scanner = new Scanner(System.in);
        money = scanner.nextLong();
        scanner.close();
        int dom1 = 100;
        int dom2 = 20;
        int dom3 = 10;
        int dom4 = 5;
        int dom5 = 1;
        int ans = 0;
        while(money >= dom1){
            money-=dom1;
            ans++;
        }
        while(money >= dom2){
            money-=dom2;
            ans++;
        }
        while(money >= dom3){
            money-=dom3;
            ans++;
        }
        while(money >= dom4){
            money-=dom4;
            ans++;
        }
        while(money >= dom5){
            money-=dom5;
            ans++;
        }
        System.out.println(ans);
      
    }
    
}
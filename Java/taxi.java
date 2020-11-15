import java.util.Scanner;
public class taxi{

    int pair_4,pair_3,pair_2,pair_1;

    public taxi(int four,int three, int two, int one){
        // constructor
        this.pair_1 = one;
        this.pair_2 = two;
        this.pair_3 = three;
        this.pair_4 = four;
    }

    public static void main(String[] args){
        
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int[] pairs_people = new int[N];
        int four = 0,three = 0,two = 0,one = 0;
        for(int i = 0; i < N ; ++i)
        {
            pairs_people[i] = scanner.nextInt();
            if(pairs_people[i] == 4){four++;}
            else if(pairs_people[i] == 3){three++;}
            if(pairs_people[i] == 2){two++;}
            if(pairs_people[i] == 1){one++;}
        }
        scanner.close();
        taxi t = new taxi(four, three, two, one);

        int tax = 0;
        tax = t.pair_4;  // all fours are using one taxi.


        // pairing the one and three groups
        while(t.pair_1 > 0 && t.pair_3 > 0){
            t.pair_3--;
            t.pair_1--;
            tax++;
        }

        // checking three pair is emptied
        if(t.pair_3 != 0){
            tax += t.pair_3;
            t.pair_3 = 0;
        }

        // surity that three and four are sent

        tax += t.pair_2/2;
        t.pair_2 = t.pair_2 % 2;

        // one or zero pair of 2 are left

        while(t.pair_1 > 0 && t.pair_2 > 0){
            t.pair_2--;
            t.pair_1 -= 2;
            tax++;
        }

        // if one is already used in the threes
        if(t.pair_2 != 0 && t.pair_2 > 0){
            tax++;
        }
        
        if(t.pair_1 != 0 && t.pair_1 > 0){
            if(t.pair_1 % 4 != 0){
                tax += t.pair_1/4 + 1;
            }else{
                tax += t.pair_1/4;
            }
        }

        System.out.println(tax);
    }
    
}
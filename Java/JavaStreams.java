import java.util.*; 
import java.util.stream.*; 

public class JavaStreams
{

    public static void main(String[] args)
    {
        List <Integer> arr =  Arrays.asList(2,3,4,5,6);
        List<Integer> square = arr.stream().map(x -> x*x). 
                           collect(Collectors.toList()); 
        System.out.println(square);

    }

}
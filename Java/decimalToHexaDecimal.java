public class decimalToHexaDecimal {

    public static void main(String[] args)
    {
        String num  = "9999999999999";
        String ndx  = "9184e729fff";
        

        long nd = Long.parseLong(num);
        
        String nhd = Long.toHexString(nd);

        

        System.out.println(nhd);
        
        
    }
    
}

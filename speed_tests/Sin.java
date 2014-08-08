public class Sin
{
    public static final double[] values = 
    {
        -3.0,
        -2.5,
        -2.0,
        -1.5,
        -1.0,
        -0.5,
         0.0,
         0.5,
         1.0,
         1.5,
         2.0,
         2.5,
         3.0,
    };
    
    public static void main(String[] args)
    {
        long start, end;
        double x = 0;
        int iterations = 100000000;
        
        start = System.currentTimeMillis();
        
        for(int k = 0; k < iterations; k++)
        {
            x += Math.sin(values[k % values.length]);
        }
        end = System.currentTimeMillis();
        
        System.out.println("x = " + x);
        System.out.println("sin(1) = " + Math.sin(1.0));
        System.out.println("time: " + (end - start));
        System.out.println("");
    }
}


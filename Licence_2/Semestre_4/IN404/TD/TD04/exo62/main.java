import org.apache.commons.math3.complex.Complex;
/**
 * Write a description of class main here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class main
{
    // instance variables - replace the example below with your own
    private int x;

    /**
     * Constructor for objects of class main
     */
    public main()
    {
        Complex c1=new Complex(1.5);
        Complex c2=new Complex(2.9);
        Complex c3=c1.add(c2);
        System.out.println(c1);
        System.out.println("+");
        System.out.println(c2);
        System.out.println("=");
        System.out.println(c3);
    }
}

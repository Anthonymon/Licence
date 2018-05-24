
/**
 * Write a description of class Fraction here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public final class Fraction
{
    // instance variables - replace the example below with your own
    private final int numerateur;
    private final int denominateur;
    
    public static final Fraction ZERO = new Fraction(0,1);
    public static final  Fraction UN = new Fraction(1,1);

    /**
     * Constructor for objects of class Fraction
     */
    public Fraction(int numerateur,int denominateur)
    {
        // initialise instance variables
        this.numerateur=numerateur;
        this.denominateur=denominateur;
    }
    
    public Fraction(int numerateur)
    {
        // initialise instance variables
        this.numerateur=numerateur;
        this.denominateur=1;
    }
    
    public Fraction()
    {
        this.numerateur=0;
        this.denominateur=1;
    }

    public int getNumerateur(){
        return this.numerateur;
    }
       
    public int getDenominateur(){
        return this.denominateur;
    }
        
    public double getDouble(){
        return this.numerateur/this.denominateur;
    }
    
    /**
     * An example of a method - replace this comment with your own
     * 
     * @param  y   a sample parameter for a method
     * @return     the sum of x and y 
     */
    public Fraction addtion(Fraction a,Fraction b)
    {
       Fraction res = new Fraction((a.getNumerateur()*b.getDenominateur()+b.getNumerateur()*a.getDenominateur()),a.getDenominateur()*b.getDenominateur());
       return res;
    }
}

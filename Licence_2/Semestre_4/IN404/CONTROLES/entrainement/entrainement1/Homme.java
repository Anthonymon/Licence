
/**
 * Write a description of class Homme here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Homme extends Donneur
{
    // instance variables - replace the example below with your own
    //private int x;

    /**
     * Constructor for objects of class Homme
     */
    public Homme(String g,String r,int d,String n,String p,int pp)
    {
        super(g,r,d,n,p,pp);
    }

    @Override
    public boolean don_possible(){
        if(this.getWeight()>60) return true;
        else return false;
    }
}

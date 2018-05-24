import exceptions.*;

/**
 * Write a description of class Femme here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Femme extends Donneur
{
    private boolean enceinte;

    /**
     * Constructor for objects of class Femme
     */
    public Femme(String g,String r,int d,String n,int p,boolean e) throws GroupeSanguinException,RhesusException,PoidsException
    {
        super(g,r,d,n,p);
        this.enceinte=e;
    }
    
    @Override
    public boolean donPossible(){
        if(super.getWeight()>50) return true;
        else return false;
    }

}

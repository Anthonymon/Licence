import exceptions.*;

/**
 * Write a description of class Homme here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Homme extends Donneur
{

    /**
     * Constructor for objects of class Homme
     */
    public Homme(String g,String r,int d,String n,int p) throws GroupeSanguinException,RhesusException,PoidsException
    {
        super(g,r,d,n,p);
    }
    
    @Override
    public boolean donPossible(){
        if(super.getWeight()>60) return true;
        else return false;
    }


}

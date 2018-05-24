
/**
 * Write a description of class Femme here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Femme extends Donneur
{
    // instance variables - replace the example below with your own
    private boolean attribut;

    public Femme(String g,String r,int d,String n,String p,int pp,boolean attribut)
    {
        super(g,r,d,n,p,pp);
        this.attribut=attribut;
    }
    
    public boolean getAttribut(){
        return this.attribut;
    }
    
    @Override
    public boolean don_possible(){
        if(this.getWeight()>50) return true;
        else return false;
    }
}

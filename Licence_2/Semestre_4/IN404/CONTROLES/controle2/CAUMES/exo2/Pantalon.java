
/**
 * Write a description of class Pantalon here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Pantalon extends Vetement
{

    /**
     * Constructor for objects of class Pantalon
     */
    public Pantalon(int i,int t)
    {
        super(i,t);
    }
    
    @Override
    public boolean repasser(int temperature) throws TemperatureException
    {
        if(super.getTempMax()<temperature) throw new TemperatureException("Erreur de Temperature");
        return true;
    }
    
    @Override
    public String toString(){
        return  "Chemise "+super.getIdentifiant()+" "+super.getTempMax();
    }
}

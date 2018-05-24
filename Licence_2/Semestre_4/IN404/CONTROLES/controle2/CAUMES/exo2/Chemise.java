
/**
 * Write a description of class Chemise here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Chemise extends Vetement
{
    // instance variables - replace the example below with your own
    private boolean imprime;

    /**
     * Constructor for objects of class Chemise
     */
    public Chemise(int i,int t,boolean b)
    {
        super(i,t);
        this.imprime=b;
    }
    
    public boolean getImprime(){
        return this.imprime;
    }
    
    @Override
    public boolean repasser(int temperature) throws TemperatureException,ImprimeException
    {
        if(super.getTempMax()<temperature) throw new TemperatureException("Erreur de Temperature");
        if(this.getImprime()==true) throw new ImprimeException("Presence d'imprimé");
        return true;
    }
    
    @Override
    public String toString(){
        String s= "Chemise "+super.getIdentifiant()+" "+super.getTempMax();
        if(this.imprime==true) s+=" Imprime";
        return s;
    }
}

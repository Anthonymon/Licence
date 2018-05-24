
/**
 * Abstract class Vetement - write a description of the class here
 * 
 * @author (your name here)
 * @version (version number or date here)
 */
public abstract class Vetement
{
    private int identifiant;
    private int tempMax;
    
    public Vetement(int i,int t){
        this.identifiant=i;
        this.tempMax=t;
    }
    
    public int getIdentifiant(){
        return this.identifiant;
    }
    
    public int getTempMax(){
        return this.tempMax;
    }
    
    public abstract boolean repasser(int temperature)throws TemperatureException,ImprimeException;
    
    @Override
    public abstract String toString();
}

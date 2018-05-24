
/**
 * Write a description of class Dvd here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Dvd extends Document
{
    // instance variables - replace the example below with your own
    private String realisateur;
    private int dateSortie;

    /**
     * Constructor for objects of class Dvd
     */
    public Dvd(String titre,String realisateur,int date)
    {
        super(titre);
        this.realisateur=realisateur;
        this.dateSortie=date;
    }

    /**
     * An example of a method - replace this comment with your own
     * 
     * @param  y   a sample parameter for a method
     * @return     the sum of x and y 
     */
    public String getRealisateur(){
        return this.realisateur;
    }
    
    public int dateSortie(){
        return this.dateSortie;
    }
    
    public boolean contient(String name){
        if(this.titre==name) return true;
        else return false;
    }
    
    @Override
    public String toString(){
        return "DVD: " + this.titre + "," + this.realisateur + "," + this.dateSortie;
    }
}


/**
 * Write a description of class Cd here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Cd extends Document
{
    // instance variables - replace the example below with your own
    private String nomArtiste;
    private String nomTitre;

    /**
     * Constructor for objects of class Cd
     */
    public String getNomArtiste(){
        return this.nomArtiste;
    }
    
    public String getNomTitre(){
        return this.nomTitre;
    }
    
    public Cd(String titre,String nomArtiste,String nomTitre)
    {
        // initialise instance variables
        super(titre);
        this.nomArtiste=nomArtiste;
        this.nomTitre=nomTitre;
    }
    
    public boolean contient(String name){
        if(this.nomTitre==name) return true;
        else return false;
    }
    
     @Override
    public String toString(){
        return "CD: " + this.titre + "," + this.nomArtiste + "," + this.nomTitre;
    }
   
}

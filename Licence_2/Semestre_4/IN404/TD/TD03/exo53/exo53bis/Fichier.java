
/**
 * Write a description of class Fichier here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Fichier extends Element
{
    // instance variables - replace the example below with your own
    private int taille;

    /**
     * Constructor for objects of class Fichier
     */
    public Fichier(String nom,int taille)
    {
        super(nom);
        this.taille=taille;
    }

    @Override
    public int getTaille(){
        return this.taille;
    }
    
    @Override
    public String getNom(){
        return super.getNom();
    }
}

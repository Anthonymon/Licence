
/**
 * Abstract class Element - write a description of the class here
 * 
 * @author (your name here)
 * @version (version number or date here)
 */
public abstract class Element
{
    // instance variables - replace the example below with your own
    protected String nom;

    public String getNom(){
        return this.nom;
    }
    
    public Element(String nom){
        this.nom=nom;
    }
    
    public abstract int getTaille();
}

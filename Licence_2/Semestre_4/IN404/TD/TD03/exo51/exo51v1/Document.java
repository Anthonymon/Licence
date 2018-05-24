
/**
 * Write a description of class Document here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
abstract class Document
{
    // instance variables - replace the example below with your own
    protected String titre;

    /**
     * Constructor for objects of class Document
     */
    public Document(String titre)
    {
        this.titre=titre;
    }
    
    public String getTitre(){
        return this.titre;
    }
    
    public boolean contient(String recherche){
        return true;
    }
}

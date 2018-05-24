
/**
 * Abstract class Document - write a description of the class here
 * 
 * @author (your name here)
 * @version (version number or date here)
 */
public abstract class Document
{
    // instance variables - replace the example below with your own
    protected String titre;

    public String getTitre(){
        return this.titre;
    }
    
    public Document(String titre){
        this.titre=titre;
    }
    
    public String getInfos(){
        return "Titre: "+this.titre+" ";
    }
}

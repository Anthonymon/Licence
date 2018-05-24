import java.util.ArrayList;
import java.util.List;
/**
 * Write a description of class Bibliotheque here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Bibliotheque
{
    // instance variables - replace the example below with your own
    private ArrayList <Document> listeDocuments;

    /**
     * Constructor for objects of class Bibliotheque
     */
    public Bibliotheque()
    {
        this.listeDocuments=new ArrayList <Document> ();
    }

    public ArrayList <Document> getListeDocuments(){
        return this.listeDocuments;
    }
    
    public void ajoutDocument(Document doc){
        this.listeDocuments.add(doc);
    }
    
    public boolean rechercheDocument(Document doc){
        for(int i=0;i<this.listeDocuments.size();i++){
            if(this.listeDocuments.get(i)==doc) return true;
        }
        return false;
    }
}

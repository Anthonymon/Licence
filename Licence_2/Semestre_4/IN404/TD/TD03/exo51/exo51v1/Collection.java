
import java.util.ArrayList;
import java.util.List;
/**
 * Write a description of class Collection here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Collection
{
    // instance variables - replace the example below with your own
    public ArrayList<Document> liste;

    /**
     * Constructor for objects of class Collection
     */
    
    public Collection(){
        this.liste=new ArrayList<Document>();
    }
    
    public void ajouterDoc(Document doc){
        this.liste.add(doc);
    }

    /**
     * An example of a method - replace this comment with your own
     * 
     * @param  y   a sample parameter for a method
     * @return     the sum of x and y 
     */
    public String lister()
    {
        String st="";
        int i;
        for(i=0;i<this.liste.size();i++){
            st+=this.liste.get(i).toString();
        }
        return st;
    }
    
    public boolean rechercher(String s){
        int i;
        for(i=0;i<this.liste.size();i++){
            if((this.liste.get(i).getTitre())==s) return true;
        }
        return false;
    }
}

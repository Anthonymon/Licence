import java.util.ArrayList;
import java.util.List;
public class Collection
{
    private ArrayList <Document> listeDocuments;

    public Collection()
    {
        this.listeDocuments=new ArrayList <Document>();
    }

    public ArrayList getListeDocuments(){
        return this.listeDocuments;
    }
    
    public void addListe(Document doc){
        this.listeDocuments.add(doc);
    }
    
    public String lister(){
        String s="";
        for(int i=0;i<this.listeDocuments.size();i++){
            s+=this.listeDocuments.get(i);
        }
        return s;
    }
    
    public boolean recherche(String s){
        for(int i=0;i<this.listeDocuments.size();i++){
            if(this.listeDocuments.get(i).recherche(s)==true) return true;
        }
        return false;
    }
}

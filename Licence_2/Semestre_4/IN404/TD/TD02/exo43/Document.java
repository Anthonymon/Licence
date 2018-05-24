import java.util.ArrayList;
import java.util.List;
/**
 * Write a description of class Document here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Document
{
    // instance variables - replace the example below with your own
    String titre;
    String auteur;
    int date;
    private ArrayList <Document> references;

    /**
     * Constructor for objects of class Document
     */
    public Document(String titre,String auteur,int annee)
    {
        this.titre=titre;
        this.auteur=auteur;
        this.date=annee;
        this.references=new ArrayList <Document>();
    }

    public String getTitre(){
        return this.titre;
    }
    
    public String getAuteur(){
        return this.auteur;
    }
    
    public int getDate(){
        return this.date;
    }
    
    public ArrayList <Document> getReferences(){
        return this.references;
    }
    
    public void ajoutReference(Document doc){
        this.references.add(doc);
    }
    
    public String affichage(){
        String s=this.getTitre()+" "+this.getAuteur()+" "+this.getDate();
        for(int i=0;i<this.references.size();i++){
            s+=this.references.get(i)+" ";
        }
        return s;
    }
}

import java.util.ArrayList;
import java.util.List;
/**
 * Write a description of class Serveur here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Serveur
{
    // instance variables - replace the example below with your own
    private ArrayList <Client> listeClients;

    /**
     * Constructor for objects of class Serveur
     */
    public Serveur()
    {
        // initialise instance variables
        this.listeClients=new ArrayList <Client> ();
    }

    public ArrayList getListeClients(){
        return this.listeClients;
    }
    
    public boolean connecter(Client c){
        for(int i=0;i<this.listeClients.size();i++){
            if(this.listeClients.get(i)==c) return false;
        }
        this.listeClients.add(c);
        return true;
    }
    
    public void diffuser(String message){
        for(int i=0;i<this.listeClients.size();i++){
            this.listeClients.get(i).recevoir(message);
        }
    }
}

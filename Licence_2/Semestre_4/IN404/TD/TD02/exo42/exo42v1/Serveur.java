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
    //private int x;
    //public String nomServeur;
    public ArrayList <Client> listeClients;
    /**
     * Constructor for objects of class Serveur
     */
    public Serveur()
    {
        this.listeClients= new ArrayList<Client>();
    }

    /**
     * An example of a method - replace this comment with your own
     * 
     * @param  y   a sample parameter for a method
     * @return     the sum of x and y 
     */
    public boolean connecter(Client client){
        for(int i=0;i<this.listeClients.size();i++){
            if(this.listeClients.get(i)==client) return false;
        }
        listeClients.add(client);
        return true;
    }
    
    public void diffuser(String message){
        for(int i=0;i<this.listeClients.size();i++){
            this.listeClients.get(i).recevoir(message);
        }
    }
}

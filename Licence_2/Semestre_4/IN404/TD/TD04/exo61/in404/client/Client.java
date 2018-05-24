package in404.client;
import in404.serveur.Serveur;


/**
 * Write a description of class Client here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Client
{
    // instance variables - replace the example below with your own
    public String nom;
    public Serveur serveur;

    /**
     * Constructor for objects of class Client
     */
    public Client(String name)
    {
        // initialise instance variables
        this.nom=name;
        this.serveur=null;
    }

    /**
     * An example of a method - replace this comment with your own
     * 
     * @param  y   a sample parameter for a method
     * @return     the sum of x and y 
     */
    public boolean seConnecter(Serveur serv){
        /*if(this.serveur==serveur) return true;
        else return false;*/
        //this.serveur=serv.this;
        if(serv.connecter(this)==true){
            this.serveur=serv;
            return true;
        }
        else return false;
    }
    
    public void envoyer(String message){
        if(this.serveur!=null) this.serveur.diffuser(message);
    }
    
    public String recevoir (String message){
        return message;
    }
}

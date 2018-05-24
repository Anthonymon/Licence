
/**
 * Write a description of class Client here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Client
{
    // instance variables - replace the example below with your own
    private String nom;
    private Serveur serveur;

    /**
     * Constructor for objects of class Client
     */
    public Client(String nom)
    {
        this.nom=nom;
        this.serveur=null;
    }

    public String getNom(){
        return this.nom;
    }
    
    public Serveur getServeur(){
        return this.serveur;
    }
    
    public boolean seConnecter(Serveur s){
        if(s.connecter(this)==true){
            this.serveur=s;
            return true;
        }
        else{
            this.serveur=null;
            return false;
        }
    }
    
    public void envoyer(String s){
        if(this.serveur!=null){
            this.serveur.diffuser(s);
        }
    }
    
    public String recevoir(String s){
        return s;
    }
}


/**
 * Abstract class Donneur - Contient la description de la classe abstraite Donneur
 * 
 * @author Clément Caumes
 * @version 1.0
 */
public abstract class Donneur
{
    // instance variables - replace the example below with your own
    private String groupeSanguin;
    private String rhesus;
    private int dateNaissance;
    private String nom;
    private String prenom;
    private int poids;

    
    public String getGroupeSanguin(){
        return this.groupeSanguin;
    }
    
    public String getRhesus(){
        return this.rhesus;
    }
    
    public int getDateNaissance(){
        return this.dateNaissance;
    }
    
    public String getNom(){
        return this.nom;
    }
    
    public String getPrenom(){
        return this.prenom;
    }
    
    public int getWeight(){
        return this.poids;
    }
    
    /**
     * Constructeur de Donneur
     */
    public Donneur(String g,String r,int d,String n,String p,int pp){
        this.groupeSanguin=g;
        this.rhesus=r;
        this.dateNaissance=d;
        this.nom=n;
        this.prenom=p;
        this.poids=pp;
    }
    
    /**
     * @param  newWeight   le nouveau poids
     */
    public void update_weight(int newWeight){
        this.poids=newWeight;
    }
    
    public abstract boolean don_possible();
}

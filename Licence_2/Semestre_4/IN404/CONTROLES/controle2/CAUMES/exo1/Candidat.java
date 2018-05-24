
public class Candidat implements Comparable
{
    // instance variables - replace the example below with your own
    private int numeroAnonyme;
    private String nom;
    private String prenom;
    private double moyenne;

    /**
     * Constructor for objects of class Candidat
     */
    public Candidat(int n,String no, String p,double m)
    {
        this.numeroAnonyme=n;
        this.nom=no;
        this.prenom=p;
        this.moyenne=m;
    }

    public int getNumeroAnonyme()
    {
        return this.numeroAnonyme;
    }
    
    public String getNom(){
        return this.nom;
    }
    
    public String getPrenom(){
        return this.prenom;
    }
    
    public double getMoyenne(){
        return this.moyenne;
    }
    
    //erreur ici je ne comprends pas pourquoi il faut rajouter implements Comparable
    @Override
    public int compareTo(Object o){
        Candidat cr=(Candidat) o;
        return this.numeroAnonyme - cr.getNumeroAnonyme();
    }
    
    @Override
    public String toString(){
        return "["+this.numeroAnonyme+" "+this.nom+" "+this.prenom+" "+this.moyenne+"]";
    }
    
    
}


public class Candidat implements Comparable
{
    private int numeroAnonyme;
    private String nom;
    private String prenom;
    private double moyenne;

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
    
    @Override
    public int compareTo(Object o){
        Candidat c=(Candidat) o;
        return this.numeroAnonyme.compareTo(c.getNumeroAnonyme());
    }
    
}

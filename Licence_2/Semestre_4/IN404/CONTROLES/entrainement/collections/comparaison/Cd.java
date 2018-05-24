package comparaison;

public class Cd implements Comparable
{
    private String auteur;
    private String titre;
    private double prix;

    public Cd(String auteur,String titre,double prix)
    {
        this.auteur=auteur;
        this.titre=titre;
        this.prix=prix;
    }
    
    public String getAuteur(){
        return this.auteur;
    }
    
    public String getTitre(){
        return this.titre;
    }
    
    public double getPrix(){
        return this.prix;
    }
    
    @Override 
    public String toString(){
        return this.getAuteur()+" "+this.getTitre()+" "+this.getPrix();
    }

    @Override
    public int compareTo(Object o){
        Cd c=(Cd)o;
        return this.auteur.compareTo(c.getAuteur());
    }
}

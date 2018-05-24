

public class CD implements Comparable
{
    private String auteur;
    private String titre;
    private double prix;

    public String getAuteur(){
        return this.auteur;
    }
    
    public String getTitre(){
        return this.titre;
    }
    
    public double getPrix(){
        return this.prix;
    }
    
    public CD(String auteur,String titre, double prix)
    {
        this.auteur=auteur;
        this.titre=titre;
        this.prix=prix;
    }

    @Override
    public int compareTo(Object o){
        CD cd=(CD)o;
        return this.auteur.compareTo(cd.getAuteur());
    }
    
    @Override
    public String toString(){
        return this.auteur;
    }
}

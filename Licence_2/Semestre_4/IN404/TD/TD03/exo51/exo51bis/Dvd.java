

public class Dvd extends Document
{
    private String realisateur;
    private int annee;
    
    public Dvd(String titre,String realisateur,int annee)
    {
        super(titre);
        this.realisateur=realisateur;
        this.annee=annee;
    }

    public String getRealisateur(){
        return this.realisateur;
    }
    
    public int getAnnee(){
        return this.annee;
    }
    
    //@Override
    public boolean recherche(String s){
        boolean decision;
        if(this.realisateur==s) decision=true;
        else decision=false;
        return (super.recherche(s) || decision);
        //return false;
    }
    
    @Override
    public String toString(){
        return "CD- Titre: "+super.titre+" Realisateur: "+this.realisateur+" Annee: "+this.annee+" ";
    }
}

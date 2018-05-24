

public class Cd extends Document
{
    private String artiste;
    private int nbTitres;

    public Cd(String titre,String artiste,int nb)
    {
        super(titre);
        this.artiste=artiste;
        this.nbTitres=nb;
        
    }

    public String getArtiste(){
        return this.artiste;
    }
    
    public int getNbTitres(){
        return this.nbTitres;
    }
    
    @Override
    public boolean recherche(String s){
        boolean decision;
        if(this.artiste==s) decision=true;
        else decision=false;
        return (super.recherche(s) || decision);
        //return ;
        /*if((this.titre==s)&&()*/
    }
    
    @Override
    public String toString(){
        return "CD- Titre: "+super.titre+" Artiste: "+this.artiste+" Titres: "+this.nbTitres+" ";
    }
}


/**
 * Write a description of class Dvd here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Dvd extends Document
{
    // instance variables - replace the example below with your own
    private String realisateur;
    private int annee;

    /**
     * Constructor for objects of class Dvd
     */
    public Dvd(String titre,String realisateur,int annee)
    {
        super(titre);
        this.realisateur=realisateur;
        this.annee=annee;
    }

    @Override
    public String getInfos(){
        return super.getInfos()+this.realisateur;
    }
}

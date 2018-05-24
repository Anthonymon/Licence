
/**
 * Write a description of class Cd here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Cd extends Document
{
    // instance variables - replace the example below with your own
    private String artiste;
    private int titres;

    /**
     * Constructor for objects of class Cd
     */
    public Cd(String titre,String artiste,int titres)
    {
        super(titre);
        this.artiste=artiste;
        this.titres=titres;
    }

    /**
     * An example of a method - replace this comment with your own
     * 
     * @param  y   a sample parameter for a method
     * @return     the sum of x and y 
     */
    @Override
    public String getInfos()
    {
        String s=super.getInfos()+this.artiste+this.titres;
        
        return s;
    }
}

import java.util.ArrayList;
/**
 * Write a description of class Repertoire here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Repertoire extends Element
{
    // instance variables - replace the example below with your own
    private int taille;
    private ArrayList <Element> contenu;

    /**
     * Constructor for objects of class Repertoire
     */
    public Repertoire(String nom)
    {
        super(nom);
        this.taille=0;
        this.contenu=new ArrayList <Element>();
    }

    @Override
    public String getNom(){
        return super.getNom();
    }
    
    @Override
    public int getTaille(){
        return this.taille;
    }
    
    public ArrayList<Element> getContenu(){
        return this.contenu;
    }
    
    public void ajoute(Element d){
        this.taille+=d.getTaille();
        this.contenu.add(d);
    }
}

/**
 * Write a description of class etd here.
 * 
 * @author clement caumes 21501810 
 */
public abstract class Article
{
    // instance variables - replace the example below with your own
    protected int codeBarre;
    protected int prixHorsTaxe;
    
    public Article(int code,int prix){
        this.codeBarre=code;
        this.prixHorsTaxe=prix;
    }
    
    public abstract double getPrix();

}

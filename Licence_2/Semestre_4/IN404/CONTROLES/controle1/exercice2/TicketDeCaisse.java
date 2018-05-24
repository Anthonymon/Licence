import java.util.ArrayList;
/**
 * Write a description of class TicketDeCaisse here.
 * 
 * @author clement caumes 2501810 
 * @version (a version number or a date)
 */
public class TicketDeCaisse
{
    // instance variables - replace the example below with your own
    private ArrayList <Article> liste;

    /**
     * Constructor for objects of class TicketDeCaisse
     */
    public TicketDeCaisse()
    {
        this.liste=new ArrayList <Article>();
    }

    public void addArticle(Article a){
        this.liste.add(a);
    }
    
    public double calculPrixTotal(){
        double calcul=0;
        for(int i=0;i<this.liste.size();i++){
            calcul+=this.liste.get(i).getPrix();
        }
        return calcul;
    }
}

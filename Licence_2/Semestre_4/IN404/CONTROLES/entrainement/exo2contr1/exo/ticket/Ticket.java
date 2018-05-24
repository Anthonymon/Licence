package exo.ticket;
import java.util.ArrayList;
import exo.article.Article;

public class Ticket
{
    // instance variables - replace the example below with your own
    private ArrayList <Article> liste;
    int prixTotal;

    /**
     * Constructor for objects of class Ticket
     */
    public Ticket()
    {
        this.liste=new ArrayList <Article> ();
        this.prixTotal=0;
    }
    
    public int getPrixTotal(){
        return this.prixTotal;
    }

    public boolean setArticle(Article a){
        boolean b=this.liste.add(a);
        if(b==true) this.prixTotal+=a.calculTVA();
        return b;
    }
}

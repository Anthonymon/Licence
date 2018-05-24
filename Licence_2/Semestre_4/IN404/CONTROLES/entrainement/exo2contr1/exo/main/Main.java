package exo.main;
import exo.ticket.Ticket;
import exo.article.nonAlimentaire.NonAlimentaire;
import exo.article.alimentaire.Alimentaire;
import exo.exceptions.negatifException.NegatifException;

public class Main
{

    public static void main(){
        try{
            Ticket t=new Ticket();
            NonAlimentaire a1=new NonAlimentaire(12,2);
            Alimentaire a2=new Alimentaire(14,15,16);
            t.setArticle(a1);
            t.setArticle(a2);
            System.out.println(t.getPrixTotal());
        }
        
        catch(NegatifException e){
            System.out.println("Le prix est negatif");
        }
        
        catch(ArithmeticException e){
            System.out.println("Erreur de prix");
        }
       
       
    }
}

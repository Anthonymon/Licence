import java.util.List;
import java.util.ArrayList;
import java.util.Iterator;
/**
 * Write a description of class Main here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Main
{
    public static void main()
    {
        ListeNombres l=new ListeNombres();
        l.ajouteListe(1);
        l.ajouteListe(2);
        l.ajouteListe(3);
        l.ajouteListe(4);
        l.ajouteListe(5);
        l.ajouteListe(6);
        l.afficherListe();
        System.out.println("ACTION\n\n");
        l.supprimerElements(3,5);
        System.out.println("\n\n");
        l.afficherListe();
        System.out.println("\n");
        l.remplace(90);
        
        l.afficherListe();

    }
}

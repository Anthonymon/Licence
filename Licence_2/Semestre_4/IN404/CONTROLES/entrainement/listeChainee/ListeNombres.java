import java.util.List;
import java.util.LinkedList;
import java.util.ListIterator;
import java.util.Iterator;

public class ListeNombres
{
    private List <Integer> l;
    
    public ListeNombres(){
        this.l=new LinkedList <Integer>();
    }
    
    public void ajouteListe(int c){
        this.l.add(c);
    }
    
    public ListIterator<Integer> myIterator(){
        return this.l.listIterator();
    }
    
    public void afficherListe(){
        ListIterator i=this.l.listIterator();
        while(i.hasNext()){
            System.out.println(i.next());
        }
    }
    
    public void remplace(int a)
    {
        ListIterator i=this.l.listIterator();
        int j;
        while(i.hasNext()){
            j=(int)i.next();
            i.remove();
            i.add(a);
        }
    }
        
        
    
    public void supprimerElements(int debut,int fin){
        Iterator i=this.l.iterator();
        int compteur=1;
        int j;
        while(i.hasNext()){
            j=(int)i.next();
            if((compteur>=debut)&&(compteur<=fin)){
                i.remove();
            }
            compteur++;
        }
    }
}

import java.util.List;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Collections;

/**
 * Write a description of class ListeCandidats here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class ListeCandidats
{
    // instance variables - replace the example below with your own
    private List <Candidat> l;

    /**
     * Constructor for objects of class ListeCandidats
     */
    public ListeCandidats()
    {
        this.l=new ArrayList <Candidat>();
    }
    
    public List <Candidat> getListe(){
        return this.l;
    }
    
    public void add(Candidat c){
        this.l.add(c);
    }
    
    @Override
    public String toString(){
        Iterator i=this.l.iterator();
        String s="";
        while(i.hasNext()){
            s+=i.next()+" ";
        }
        return s;
    }
    
    public void afficherOrdre(){
        Collections.sort(this.l);
        Iterator i=this.l.iterator();
        String s="";
        while(i.hasNext()){
            s+=i.next()+",";
        }
    }
    
    public void afficherTroisMeilleurs(){
    Collections.sort(this.l,new ComparateurCandidat());
     Iterator i=this.l.iterator();
     String s="";
     int compteur=0;
     System.out.println("Les trois meilleurs sont :");
     while(i.hasNext()&&(compteur<3)){
         System.out.println(i.next());
         compteur++;
     }
    }

}

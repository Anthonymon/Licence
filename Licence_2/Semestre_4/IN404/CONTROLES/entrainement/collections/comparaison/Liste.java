package comparaison;
import java.util.List;
import java.util.ArrayList;
import java.util.Iterator;


public class Liste
{
    private List<Cd> myListe;

    /**
     * Constructor for objects of class Liste
     */
    public Liste()
    {
        this.myListe=new ArrayList<Cd>();
    }
    
    public List<Cd> getListe(){
        return this.myListe;
    }

    public void setListe(Cd c){
        this.myListe.add(c);
    }
    
    @Override
    public String toString(){
        Iterator i=this.myListe.iterator();
        String s="";
        while(i.hasNext()){
            s+=i.next()+"+";
        }
        return s;
    }
}

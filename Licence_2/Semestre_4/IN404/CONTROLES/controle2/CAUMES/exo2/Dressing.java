import java.util.HashSet;
import java.util.Set;
import java.util.Iterator;

/**
 * Write a description of class Dressing here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Dressing
{
    private Set<Vetement> s;
    
    public Dressing(){
        this.s=new HashSet<Vetement>();
    }
    
    public void setElement(Vetement v){
        this.s.add(v);
    }
    
    @Override
    public String toString(){
        Iterator i=this.s.iterator();
        String s="";
        while(i.hasNext()){
            s+=(String)i.next().toString()+";";
        }
        return s;
    }
}

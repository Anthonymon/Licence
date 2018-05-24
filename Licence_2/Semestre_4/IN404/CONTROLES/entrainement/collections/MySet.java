import java.util.HashSet;
import java.util.Set;
import java.util.Iterator;

public class MySet
{
    private Set<String> s;

    public MySet()
    {
        this.s=new HashSet <String> ();
    }
    
    public void setElement(String s){
       this.s.add(s);
    }  
    
    @Override
    public String toString(){
        Iterator i=this.s.iterator();
        String s="";
        while(i.hasNext()){
            s+=(String)i.next()+" ";
        }
        
        return s;
    }
}

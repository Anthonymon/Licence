import java.util.ArrayList;
import java.util.List;
import java.util.ListIterator;

public class MyList
{
    private List <String> liste;
    
    public MyList(){
        this.liste=new ArrayList <String>();
    }
    
    public void setElement(String s){
        this.liste.add(s);   
    }
    
    @Override
    public String toString(){
        ListIterator i=this.liste.listIterator();
        String s="";
        while(i.hasNext()){
            s+=(String)i.next()+" ";
        }
        while(i.hasPrevious()){
            s+=(String)i.previous()+" ";
        }
        
        return s;
    }
}

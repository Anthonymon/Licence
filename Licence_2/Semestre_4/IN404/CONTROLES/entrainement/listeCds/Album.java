import java.util.List;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Collections;

public class Album
{
    // instance variables - replace the example below with your own
    private List <Cd> l;
    
    public Album(){
        this.l=new ArrayList<Cd>();
    }
    
    public void nouveauCd(Cd c){
        this.l.add(c);
    }
    
    public void afficheAlbum(){
        Iterator i=this.l.iterator();
        while(i.hasNext()){
            System.out.println(i.next());
        }
    }
    
    public void tri(){
        Collections.sort(this.l);
    }
}

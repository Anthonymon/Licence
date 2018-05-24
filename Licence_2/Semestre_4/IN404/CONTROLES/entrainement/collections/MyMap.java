import java.util.Map;
import java.util.HashMap;
import java.util.Set;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Map.Entry;
import java.util.Collections;
import java.util.ArrayList;

public class MyMap
{
    private Map<Integer,String> m; //key,value

    public MyMap()
    {
        this.m=new HashMap<Integer,String>();
    }

    public void setElement(Integer a,String key){
        this.m.put(a,key);
    }
    
    public void myPut(int key){
        System.out.println(this.m.get(key));
    }
    
    public void listeCles(){
        Set <Integer> s=this.m.keySet();
        Iterator i=s.iterator();
        while(i.hasNext()){
            System.out.print(i.next()+" ");
        }
    }
    
    public void listeValeurs(){
        Collections c=(Collections)this.m.values();
        
    }
    
    public void parcourirMap(){
        Set<Entry<Integer,String>> s=this.m.entrySet();
        Entry<Integer,String> e;
        Iterator<Entry<Integer,String>> i=s.iterator();
        while(i.hasNext()){
            e=i.next();
            System.out.println("("+e.getKey()+","+e.getValue()+")");
        }
    }
}

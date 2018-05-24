import java.util.Queue;
import java.util.ArrayDeque;
import java.util.Iterator;

public class MyQueue
{
    // instance variables - replace the example below with your own
    private Queue <String> liste;

    public MyQueue()
    {
        this.liste=new ArrayDeque<String>();
    }

    public void setElement(String s){
        this.liste.add(s);   
    }
    
    @Override
    public String toString(){
        Iterator i=this.liste.iterator();
        String s="";
        while(i.hasNext()){
            s+=(String)i.next()+" ";
        }
        return s;
    }
}

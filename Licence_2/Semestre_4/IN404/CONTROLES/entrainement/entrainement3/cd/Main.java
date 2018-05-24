import java.util.ArrayList;
import java.util.List;
import java.util.Collections;
/**
 * Write a description of class Main here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Main
{

    public Main()
    {
        List <CD> l=new ArrayList <CD>();
        l.add(new CD("AB","V",5));
        l.add(new CD("ZM","F",3));
        l.add(new CD("DE","T",10));
        Collections.sort(l);
        System.out.println(l);
        
    }
}

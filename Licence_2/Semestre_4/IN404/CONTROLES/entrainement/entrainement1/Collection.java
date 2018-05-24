import java.util.List;
import java.util.ArrayList;
/**
 * Write a description of class Collection here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Collection
{
    // instance variables - replace the example below with your own
    private ArrayList <Donneur> listeDonneurs;

    public Collection()
    {
        this.listeDonneurs= new ArrayList <Donneur> ();
    }

    public ArrayList <Donneur> getListeDonneurs(){
        return this.listeDonneurs;
    }
}

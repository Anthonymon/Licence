import java.util.ArrayList;
import java.util.Collections;
import java.util.ListIterator;

/**
 * Enumeration class Main - write a description of the enum class here
 * 
 * @author (your name here)
 * @version (version number or date here)
 */
public enum Main
{
    ENVIRONNEMENT;
    
    public void run(){
        ArrayList <Integer> liste=new ArrayList<Integer>();
        for(int i=0;i<10;i++){
            liste.add(i);
        }
        Collections.shuffle(liste);
        int e;
        ListIterator it=liste.listIterator();
        while(it.hasNext()){
            e=(int)it.next();
            System.out.println(e);
        }
        while(it.hasPrevious()){
            it.previous();
        }
        Collections.sort(liste);
        it=liste.listIterator();
        while(it.hasNext()){
            e=(int)it.next();
            System.out.println(e);
        }
    }
    
    public static void main(){
        ENVIRONNEMENT.run();
    }
}

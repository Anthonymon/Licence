import java.io.*;

public class Main
{
    public static void main(){
        try
        {
            TableHachage t=new TableHachage();
            t.remplitTableHachage("test");
            t.afficheTableHachage();
        }
        
        catch(IOException e)
        {
            System.out.println("Erreur");
        }
    }
}

import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.FileReader;
/**
 * Write a description of class Lecteur here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Lecteur
{
    // instance variables - replace the example below with your own
    private int nbLignes;
    private FileReader file;
    
    public Lecteur(String name) throws IOException
    {
        this.nbLignes=0;
        //1e possibilité
        this.lire (name);
    }
    
    public void lire (String name) throws IOException {
        
        try {
            int c;
        this.file=new FileReader(name); 
         // le thros se trouve ds FileReader
        while ((c = file.read()) != -1){
        if(c == '\n') this.nbLignes++;
        }
        this.nbLignes++;
        }
        catch(FileNotFoundException e){
            System.out.println("Fichier Incorrect");
        }
        /*//2e possibilité (celle du cours)
        try( this.file = new FileReader(name);) //un bloc avec des parenthèses et sans catch ni finally
        {
            while ((c = file.read()) != -1); // while fgetc != EOF
            
        
        }*/
    
    
    
    }

    
}

import java.io.FileReader;
import java.io.BufferedReader;
import java.io.IOException;
import java.nio.file.*;
/**
 * Write a description of class Contain here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Contain
{
    // instance variables - replace the example below with your own
    //private int x;

    public Contain(String s,String fileName) /*throws IOException*/
    {
        try{
            System.out.println("Test");
            lecture(s,fileName);
        }
        catch(IOException e){
            System.out.println("PROBLEME\n");
        }
    }
    
    public void lecture(String s,String fileName) throws IOException
    {
        Path inPath=Paths.get(fileName);
        try(BufferedReader in=Files.newBufferedReader(inPath);){
            String line;int nbLignes=0;
            while((line=in.readLine())!=null){ nbLignes++;
            if(line.contains(s)) System.out.println(nbLignes);}
        }
        
    }
}

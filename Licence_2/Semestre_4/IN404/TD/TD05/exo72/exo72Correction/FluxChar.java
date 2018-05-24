import java.io.FileReader;
import java.io.IOException;
/**
 * Write a description of class FluxChar here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class FluxChar
{
    // instance variables - replace the example below with your own
    //private int x;
     public FluxChar(String name){
         try{
             System.out.println("NB de lignes :"+nombreL(name));
            }
         catch(IOException e){
             System.out.println("Fichier Invalide");
            }
     }
   
    /**
     * Constructor for objects of class FluxChar
     */
        private static int nombreL(String fileName) throws IOException{
            int nbLignes=0;
            try(FileReader in=new FileReader(fileName);){
                int c;
                while((c=in.read())!=-1)
                    if(c=='\n') nbLignes++;
                 return nbLignes+1;
            }
            
        }
}

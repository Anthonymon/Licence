import java.io.*;
/**
 * Enumeration class Main - write a description of the enum class here
 * 
 * @author (your name here)
 * @version (version number or date here)
 */
public enum Main
{
    ENVIRONNEMENT;
    
    public void run(String [] args){
    try{
       CalculLignes c=new CalculLignes(args[0]);
    }
    catch(AucuneLigneException e){
        System.out.println("Aucune Ligne dans le fichier");
    }
    catch(IOException e){
       System.out.println("Erreur Fichier incorrect");
    }
    }
    
    public static void main(String[] args){
        ENVIRONNEMENT.run(args);
    }
}

import java.util.Hashtable;
import java.io.*;
//import java.nio.*;
import java.nio.file.*;
import java.util.Collections;

public class CompterMots
{
    public static void main(String[] args) throws IOException
    {
        Hashtable<String,Integer> table=new Hashtable<String,Integer>();
        Path inPath=Paths.get(args[1]);
        String line=" ";
        String[] spl;
        Collections col;
        int i;
        try(BufferedReader in=Files.newBufferedReader(inPath);){
            while((line=in.readLine())!=null){
                spl=line.split(" ");
                for(i=0;i<spl.length();i++){
                    
                }
            }
        }
    }
}

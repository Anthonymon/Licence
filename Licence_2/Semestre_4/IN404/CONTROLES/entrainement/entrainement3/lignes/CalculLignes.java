import java.io.*;

public class CalculLignes
{
    public CalculLignes(String name) throws IOException,AucuneLigneException
    {
        try(FileReader f=new FileReader(name);){
            int i=0;
            int c='a';
            while(c!=-1){
                c=f.read();
                if(c=='\n') i++;
            }
            if(i==0) throw new AucuneLigneException();
            System.out.println("Nombre de lignes: "+i);
        }

    }

}

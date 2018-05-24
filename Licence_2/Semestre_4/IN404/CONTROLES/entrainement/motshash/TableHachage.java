import java.util.Map;
import java.util.HashMap;
import java.util.Map.Entry;
import java.io.*;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.Files;
import java.io.*;
import java.util.Set;
import java.util.HashSet;
import java.util.Iterator;

public class TableHachage
{

    private Map<String,Integer> m;
    
    public TableHachage()
    {
        this.m= new HashMap<String,Integer>();
    }

    public void remplitTableHachage(String inFile)throws IOException{
        Path inPath=Paths.get(inFile);
        try(BufferedReader in=Files.newBufferedReader(inPath);)
        {
            String line;
            int j;
            while((line=in.readLine())!=null){
                String [] parties=line.split(" ");
                for(j=0;j<parties.length;j++){
                    //this.m.put(parties[i],1);
                    Set<Entry<String,Integer>> s=this.m.entrySet();
                    Entry<String,Integer> e;
                    Iterator <Entry<String,Integer>> i=s.iterator();
                    while(i.hasNext()){
                        e=i.next();
                        if(e.getKey()==parties[j]){
                            this.m.put(parties[j],e.getValue()+1);
                        }
                        else this.m.put(parties[j],1);
                    }
                    
                }
            }
            
        }
    }
    
    public void afficheTableHachage(){
        Set <Entry<String,Integer>> s=this.m.entrySet();
        Entry<String,Integer> e;
        Iterator<Entry<String,Integer>> i=s.iterator();
        while(i.hasNext()){
            e=i.next();
            System.out.println(e.getKey()+"-->"+e.getValue());
        }
        System.out.println("A\n");
    }
}



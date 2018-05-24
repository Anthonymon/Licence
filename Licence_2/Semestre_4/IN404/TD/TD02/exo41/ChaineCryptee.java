
/**
 * Write a description of class ChaineCryptee here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class ChaineCryptee
{
    // instance variables - replace the example below with your own
    private String chaineCryptee;
    private int decalage;

    private static char decaleCaractere(char c,int decalage){
        return (c<'a' || c>'z')? c: (char)(((c-'a'+decalage)%26)+'a');
    }
    
    
    
    /**
     * Constructor for objects of class ChaineCryptee
     */
    private ChaineCryptee(String chaine1,int key1)
    {
        // initialise instance variables
        if(chaine1!=null){
            this.chaineCryptee=chaine1;
            this.decalage=key1;
        }
        else {
            this.chaineCryptee="";
            this.decalage=0;
        }
        
    }
    
    public static ChaineCryptee FromCrypted(String s,int i){
        return new ChaineCryptee(s,i);
    }
    
    public static ChaineCryptee FromDecrypted(String s,int i){
               String news="";
        for(i=0;i<s.length();i++){
            news+=decaleCaractere(s.charAt(i),i);
        }
        return new ChaineCryptee(news,i);
    }
    
    /**
     * An example of a method - replace this comment with your own
     * 
     * @param  y   a sample parameter for a method
     * @return     the sum of x and y 
     */
    public String decrypte()
    {
      //return this.chaineClaire;
      int i;
        String newe="";
        for(i=0;i<this.chaineCryptee.length();i++){
            newe+=decaleCaractere(this.chaineCryptee.charAt(i),-this.decalage);
        }
        return newe;
    }
    
    public String crypte(){
       return this.chaineCryptee;
        
    }
    
    
}

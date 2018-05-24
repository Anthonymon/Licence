

public /*abstract*/ class Document
{
    // instance variables - replace the example below with your own
    protected String titre;
    
    public Document(String titre){
        this.titre=titre;
    }
    
    public String getTitre(){
        return this.titre;
    }
    
    public boolean recherche(String s){
        if(this.titre==s) return true;
        else return false;
    }
}

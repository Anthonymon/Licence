import java.util.LinkedList;

public interface TableVilles
{
    public void ajouterVille(Ville v);
    
    public Ville rechercherVille(double latitude,double longitude);
    
    public int nombreVilles();
    
    public String infos();
    
    public LinkedList<Ville> traverser();
}

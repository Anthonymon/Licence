
public class Ville 
{
    private String nom;
    private double latitude;
    private double longitude;
    
    public Ville(String nom,double latitude, double longitude)
    {
        this.nom=nom;
        this.latitude=latitude;
        this.longitude=longitude;
    }
    
    public String getNom(){
        return this.nom;
    }
    
    public double getLatitude(){
        return this.latitude;
    }
    
    public double getLongitude(){
        return this.longitude;
    }
    
    @Override
    public String toString(){
        return this.nom+" "+this.getLatitude()+" "+this.getLongitude();
    }
    
    public int compareTo(Ville v){
        return this.getNom().compareTo(v.getNom());
    }
}

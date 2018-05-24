/**
 * Write a description of class etd here.
 * 
 * @author clement caumes 21501810
 * @version (a version number or a date)
 */
import java.util.ArrayList;

public class Employe
{
    private String nom;
    private String prenom;
    private String phone;
    private ArrayList <Formation> inscriptions;

    public Employe(String nom,String prenom)
    {
        this.nom=nom;
        this.prenom=prenom;
        this.phone=null;
        this.inscriptions=new ArrayList <Formation>();
    }
    
    public Employe(String nom,String prenom,String phone){
        this.nom=nom;
        this.prenom=prenom;
        this.phone=phone;
        this.inscriptions=new ArrayList <Formation>();
    }
    
    public void setPhone(String phone){
        this.phone=phone;
    }

    public boolean addFormation(Formation formation){
        if(formation.addEmploye(this)==true){
            this.inscriptions.add(formation);
            return true;
        }
        else return false;
    }
}

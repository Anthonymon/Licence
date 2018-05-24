package exo.employe;
import exo.formation.Formation;
import exo.exceptions.formationException.FormationException;
import exo.exceptions.employeException.EmployeException;
import java.util.ArrayList;

public class Employe
{
    private String nom;
    private String prenom;
    private String phone;
    private ArrayList <Formation> listeFormations;

    public Employe(String nom,String prenom)
    {
        this.nom=nom;
        this.prenom=prenom;
        this.phone=null;
        this.listeFormations=new ArrayList<Formation>();
    }
    
    public Employe(String nom,String prenom,String phone){
        this.nom=nom;
        this.prenom=prenom;
        this.phone=phone;
        this.listeFormations=new ArrayList<Formation>();
    }

    public void setPhone(String phone){
        this.phone=phone;
    }
    
    public String getNom(){
        return this.nom;
    }
    
    public String getPrenom(){
        return this.prenom;
    }
    
    public String getPhone(){
        return this.phone;
    }
    
    public boolean addFormation(Formation f)throws FormationException,EmployeException{
            if(f.addEmploye(this)==true){
                this.listeFormations.add(f);
                return true;
            }
            else{
                throw new FormationException("Formation invalide");
            }
    }
    
}


package exo.formation;
import exo.employe.Employe;
import java.util.ArrayList;
import exo.exceptions.employeException.EmployeException;

public class Formation
{
    private String intitule;
    private String date;
    private ArrayList <Employe> inscrits;

    /**
     * Constructor for objects of class Formation
     */
    public Formation(String intitule,String date)
    {
        this.intitule=intitule;
        this.date=date;
        this.inscrits=new ArrayList <Employe>();
    }

    public String getDate(){
        return this.date;
    }
    
    public boolean addEmploye(Employe e)throws EmployeException {
        //try{
           if(this.inscrits.size()<15){
             return this.inscrits.add(e);
           }
           else{
               throw new EmployeException("erreur");
            }
        //}
    }
}

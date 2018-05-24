package exo.main;
import exo.formation.Formation;
import exo.employe.Employe;
import exo.exceptions.formationException.FormationException;
import exo.exceptions.employeException.EmployeException;


/**
 * Write a description of class Main here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Main
{
    public static void main(){
        try{
        Employe e=new Employe("clement","caumes");
        e.addFormation(null);
    }
    catch(FormationException e){
        System.out.println("Erreur formation");
    }
    
    catch(EmployeException e){
        System.out.println("Erreur employe");
    }
    catch(NullPointerException e){
        System.out.println("Erreur NULL");
    }
    }
}

/**
 * Write a description of class etd here.
 * 
 * @author clement caumes 21501810
 * @version (a version number or a date)
 */

import java.util.ArrayList;

public class Formation
{
    private String intitule;
    private String date;
    private ArrayList <Employe> listeEmployes;

    public Formation(String intitulee,String date)
    {
        this.intitule=intitule;
        this.date=date;
        this.listeEmployes=new ArrayList <Employe>();
    }

    public String getDate(){
        return this.date;
    }
    
    public boolean addEmploye(Employe employe){
        if(this.listeEmployes.size()>=15) return false;
        else{
            for(int i=0;i<this.listeEmployes.size();i++){
                if(this.listeEmployes.get(i)==employe) return false;
            }
            return this.listeEmployes.add(employe);
        }
    }
}

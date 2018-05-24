import java.util.Collections;
import java.util.List;
import java.util.ArrayList;

/**
 * Write a description of class Main here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Main
{
    public static void main(){
        Candidat c1=new Candidat(12,"cle","caum",12);
        Candidat c2=new Candidat(14,"clem","gdhe",16);
        Candidat c3=new Candidat(15,"fle","kdld",19);
        Candidat c4=new Candidat(16,"ghj","lmp",20);
        Candidat c5=new Candidat(17,"fd","lom",11);
        ListeCandidats l=new ListeCandidats();
        l.add(c1);
        l.add(c2);
        l.add(c3);
        l.add(c4);
        l.add(c5);
        l.afficherOrdre(); //si le compareTo fonctionnait on pourrait utiliser cette fonction
        l.afficherTroisMeilleurs();
    }
}

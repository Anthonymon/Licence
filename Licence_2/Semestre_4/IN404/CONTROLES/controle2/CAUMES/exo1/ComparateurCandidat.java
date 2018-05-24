import java.util.Comparator;
/**
 * Write a description of class ComparateurCandidat here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class ComparateurCandidat implements Comparator<Candidat>
{
    public int compare(Candidat c1,Candidat c2){
        return (int)(c2.getMoyenne()-c1.getMoyenne());
    }
}

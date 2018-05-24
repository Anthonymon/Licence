package comparaison;
import java.util.Comparator;

public class ComparateurCd implements Comparator<Cd>
{
    public int compare(Cd cd1,Cd cd2){
        return (int)( cd1.getPrix()-cd2.getPrix());
    }
}

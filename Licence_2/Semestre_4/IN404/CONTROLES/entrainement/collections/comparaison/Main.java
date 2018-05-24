package comparaison;
import java.util.Collections;
import java.util.ArrayList;
import java.util.List;

public class Main
{
    public static void main(){
        Liste l=new Liste();
        Cd cd1=new Cd("zzzzzz","zbeub",2);
        Cd cd2=new Cd("yassin","heheh",4);
        l.setListe(cd1);
        l.setListe(cd2);
        System.out.println(l.toString());
        Collections.sort(l.getListe()); //utilisé pour toCompare
        System.out.println(l.toString());
        Collections.sort(l.getListe(),new ComparateurCd()); //utilisé pour la classe ComparateurCd
        System.out.println(l.toString());
    }
}

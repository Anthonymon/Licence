import exceptions.*;

public class Main
{
    public static void main()
    {
        try
        {
            Homme h1=new Homme("A","+",1997,"Caumes",75);
            Femme f1=new Femme("B","-",2000,"Zbeub",55,false);
        }
        
        catch(GroupeSanguinException e){
            System.out.println("Groupe Sanguin Invalide");
        }
        
        catch(RhesusException e){
            System.out.println("Rhesus Invalide");
        }
        
        catch(PoidsException e){
            System.out.println("Poids Invalide");
        }
        
    }
}

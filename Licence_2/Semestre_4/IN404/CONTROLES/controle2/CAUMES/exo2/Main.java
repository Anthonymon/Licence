
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
            Dressing d=new Dressing();
            
            Chemise c=new Chemise(1,50,true);
            Pantalon p=new Pantalon(2,60);
            d.setElement(c);
            d.setElement(p);
            System.out.println(d.toString());
            c.repasser(45);
            p.repasser(70);
        }
        catch(TemperatureException e){
            System.out.println("Temperature trop elevee");
        }
        catch(ImprimeException e){
            System.out.println("Presence d'imprime, veuillez retourner le vetement");
        }
    }
}

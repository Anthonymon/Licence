
public class Main
{
    public static void main(){
        Constante deux=new Constante(2);
        Constante trois=new Constante(3);
        Constante quatre=new Constante(4);
        Mult multiplication=new Mult(trois,quatre);
        Plus resultat=new Plus(deux,multiplication);
        System.out.print(resultat.toString()+"=");
        System.out.println(resultat.evaluate());
    }
}

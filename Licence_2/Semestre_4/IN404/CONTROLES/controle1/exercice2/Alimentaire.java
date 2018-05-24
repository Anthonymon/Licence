
/**
 * 
 * @author clement caumes 21501810
 */
public class Alimentaire extends Article
{
    // instance variables - replace the example below with your own
    private int datePeremption;

    /**
     * Constructor for objects of class Alimentaire
     */
    public Alimentaire(int code,int prix,int date)
    {
        super(code,prix);
        this.datePeremption=date;
    }

    @Override
    public double getPrix(){
        return (super.prixHorsTaxe+super.prixHorsTaxe*0.055);
    }
}

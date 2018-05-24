
/**
 * Write a description of class NonAlimentaire here.
 * 
 * @author clement caumes 21501810
 * @version (a version number or a date)
 */
public class NonAlimentaire extends Article
{

    /**
     * Constructor for objects of class NonAlimentaire
     */
    public NonAlimentaire(int code,int prix)
    {
        super(code,prix);
    }

    @Override
    public double getPrix(){
        return (super.prixHorsTaxe+super.prixHorsTaxe*0.20);
    }
    
}

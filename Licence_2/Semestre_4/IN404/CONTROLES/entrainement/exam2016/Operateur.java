
public abstract class Operateur implements Calculable
{
    protected Calculable opGauche;
    protected Calculable opDroite;

    public Operateur(Calculable opGauche,Calculable opDroite){
        this.opGauche=opGauche;
        this.opDroite=opDroite;
    }
}

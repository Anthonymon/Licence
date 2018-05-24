
public class Plus extends Operateur
{
    public Plus(Calculable opGauche,Calculable opDroite){
        super(opGauche,opDroite);
    }
    
    @Override
    public double evaluate(){
        return opGauche.evaluate()+opDroite.evaluate();
    }
    
    @Override
    public String toString(){
        return ""+super.opGauche+"+"+super.opDroite;
    }
}

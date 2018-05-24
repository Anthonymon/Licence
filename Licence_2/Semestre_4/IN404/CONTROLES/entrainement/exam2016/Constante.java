
public class Constante implements Calculable
{
    private double value;

    public Constante(double value){
        this.value=value;
    }
    
    @Override
    public double evaluate(){
        return value;
    }
    
    @Override
    public String toString(){
        return ""+this.evaluate();
    }

}

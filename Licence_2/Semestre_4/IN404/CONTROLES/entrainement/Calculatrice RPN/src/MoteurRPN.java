import java.util.Stack;
import exc.*;

public class MoteurRPN {

	private static final double MIN_VALUE = 5000.0; //en valeur absolue
	private static final double MAX_VALUE = 5000.0;
	private Stack<Double> pileOpérandes;
	
	public MoteurRPN() {
		pileOpérandes = new Stack<Double>();
	}
	
	public Double enregistrerDouble(double val) throws ValueException {
		if (val < -MIN_VALUE)
			throw new MinValueException(val);
		else if (val > MAX_VALUE)
			throw new MaxValueException(val);
		return pileOpérandes.push(val);
	}
	
	private Double appliquerOpération(Opération op){
		return op.eval(pileOpérandes.pop(), pileOpérandes.pop());
	}
	
	public Double enregistrerAppliquerOpération(Opération op){
		return enregistrerDouble(appliquerOpération(op));
	}
	
	public boolean opérationPossible(){
		return pileOpérandes.size() >= 2;
	}
	
	public String listerValues(){
		return "MIN_VALUE = " + -MIN_VALUE + "; MAX_VALUE = " + MAX_VALUE + ";";
	}
	
	public String listerOpérandes(){
		String str = "";
		for(Double d: pileOpérandes){
			str += d + " ";
		}
		return str;
	}
}	
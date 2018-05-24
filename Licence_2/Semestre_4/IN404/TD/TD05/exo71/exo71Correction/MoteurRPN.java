import java.util.Stack;

public class MoteurRPN {

	private static final double MIN_VALUE = 5000.0; //en valeur absolue
	private static final double MAX_VALUE = 5000.0;
	private Stack<Double> pileOperandes;
	
	public MoteurRPN() {
		pileOperandes = new Stack<Double>();
	}
	
	public Double enregistrerDouble(double val) throws ValueException {
		if (val < -MIN_VALUE)
			throw new MinValueException(val);
		else if (val > MAX_VALUE)
			throw new MaxValueException(val);
		return pileOperandes.push(val);
	}
	
	private Double appliquerOperation(Operation op){
		return op.eval(pileOperandes.pop(), pileOperandes.pop());
	}
	
	public Double enregistrerAppliquerOperation(Operation op){
		return enregistrerDouble(appliquerOperation(op));
	}
	
	public boolean operationPossible(){
		return pileOperandes.size() >= 2;
	}
	
	public String listerValues(){
		return "MIN_VALUE = " + -MIN_VALUE + "; MAX_VALUE = " + MAX_VALUE + ";";
	}
	
	public String listerOperandes(){
		String str = "";
		for(Double d: pileOperandes){
			str += d + " ";
		}
		return str;
	}
}
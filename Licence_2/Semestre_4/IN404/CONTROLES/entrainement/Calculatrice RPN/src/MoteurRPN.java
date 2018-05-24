import java.util.Stack;
import exc.*;

public class MoteurRPN {

	private static final double MIN_VALUE = 5000.0; //en valeur absolue
	private static final double MAX_VALUE = 5000.0;
	private Stack<Double> pileOp�randes;
	
	public MoteurRPN() {
		pileOp�randes = new Stack<Double>();
	}
	
	public Double enregistrerDouble(double val) throws ValueException {
		if (val < -MIN_VALUE)
			throw new MinValueException(val);
		else if (val > MAX_VALUE)
			throw new MaxValueException(val);
		return pileOp�randes.push(val);
	}
	
	private Double appliquerOp�ration(Op�ration op){
		return op.eval(pileOp�randes.pop(), pileOp�randes.pop());
	}
	
	public Double enregistrerAppliquerOp�ration(Op�ration op){
		return enregistrerDouble(appliquerOp�ration(op));
	}
	
	public boolean op�rationPossible(){
		return pileOp�randes.size() >= 2;
	}
	
	public String listerValues(){
		return "MIN_VALUE = " + -MIN_VALUE + "; MAX_VALUE = " + MAX_VALUE + ";";
	}
	
	public String listerOp�randes(){
		String str = "";
		for(Double d: pileOp�randes){
			str += d + " ";
		}
		return str;
	}
}	
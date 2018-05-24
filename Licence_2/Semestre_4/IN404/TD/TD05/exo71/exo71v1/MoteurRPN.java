import java.util.ArrayList;
/**
 * Write a description of class MoteurRPN here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
/*public class MoteurRPN
{
    private ArrayList <Integer> Operandes;

    public MoteurRPN()
    {
        this.Operandes=new ArrayList<Integer>();
    }

    public void getOperandes(){
        for(int i=0;i<this.Operandes.size();i++){
            System.out.println(this.Operandes.get(i)+" ");
        }
    }
    
    public void addOperandes(int i){
        this.Operandes.add(i);
    }
    
    public double appliqueOperation(int a,int b,Operation k){
        return k.eval(a,b);
    }
}*/

import java.util.Stack;
//import exc.valueException;
//import exc.*;

public class MoteurRPN {

	private static final double MIN_VALUE = 5000.0; //en valeur absolue
	private static final double MAX_VALUE = 5000.0;
	private Stack<Double> pileOperandes;
	
	public MoteurRPN() {
		pileOperandes = new Stack<Double>();
	}
	
	public Double enregistrerDouble(double val) throws Exception {
		if (val < -MIN_VALUE)
			throw new Exception();
		else if (val > MAX_VALUE)
			throw new Exception();
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
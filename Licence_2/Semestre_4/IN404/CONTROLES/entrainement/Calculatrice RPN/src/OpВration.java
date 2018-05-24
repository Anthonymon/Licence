
public enum Opération {
	PLUS('+') { 
		public double eval(double operande1, double operande2) {
			return operande1 + operande2;
		}
	},
	MOINS('-') {
		public double eval(double operande1, double operande2) {
			return operande1 - operande2;
		}
	},
	MULT('*') {
		public double eval(double operande1, double operande2) {
			return operande1 * operande2;
		}
	},
	DIV('/') {
		public double eval(double operande1, double operande2) {
			return operande1 / operande2;
		}
	};
	
	private char symbole;

	private Opération(char symbole) {
		this.symbole = symbole;
	}
	
	public abstract double eval(double operande1, double operande2);

	public char getSymbole() {
		return symbole;
	}
	
}

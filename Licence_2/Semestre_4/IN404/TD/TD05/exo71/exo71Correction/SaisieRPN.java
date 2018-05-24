import java.util.Scanner;

public class SaisieRPN {

	private MoteurRPN moteur;
	private Scanner sc;

	public SaisieRPN() {
		this.moteur = new MoteurRPN();
		this.sc = new Scanner(System.in);
	}

	public void saisieCalculatrice() {
		String str = "";
		boolean sortie = false;
		System.out.println("Entrez un nombre, un operation ou 'exit' pour quitter:");
		while (!sortie) {
			if (sc.hasNextDouble()) { // Double
				moteur.enregistrerDouble(sc.nextDouble());
				System.out.println(moteur.listerOperandes());
				str = sc.nextLine(); // (aller � la ligne suivante apr�s nextDouble)
			}
			else {
				str = sc.nextLine();
				if (this.isOperation(str)) // Op�ration
					if (moteur.operationPossible()) {
						moteur.enregistrerAppliquerOperation(this.renvoieOperation(str));
						System.out.println(moteur.listerOperandes());
					} 
					else
						System.out.println("Operation necessite au moins 2 entiers dans la pile.");
				else if (str.equals("exit")) // Exit
					sortie = true;
				else
					System.out.println("Saisie incorrecte.");
			}
		}
	}
	
	public void afficherValues(){
		System.out.println(moteur.listerValues());
	}
	
	private boolean isOperation(String str) {
		if (str.length() != 1)
			return false;

		return this.renvoieOperation(str) != null;
	}

	private Operation renvoieOperation(String str) {
		for (Operation op : Operation.values())
			if (str.charAt(0) == op.getSymbole())
				return op;
		return null;

	}
}

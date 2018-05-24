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
		System.out.println("Entrez un nombre, un op�ration ou 'exit' pour quitter:");
		while (!sortie) {
			if (sc.hasNextDouble()) { // Double
				moteur.enregistrerDouble(sc.nextDouble());
				System.out.println(moteur.listerOp�randes());
				str = sc.nextLine(); // (aller � la ligne suivante apr�s nextDouble)
			}
			else {
				str = sc.nextLine();
				if (this.isOp�ration(str)) // Op�ration
					if (moteur.op�rationPossible()) {
						moteur.enregistrerAppliquerOp�ration(this.renvoieOp�ration(str));
						System.out.println(moteur.listerOp�randes());
					} 
					else
						System.out.println("Op�ration n�cessite au moins 2 entiers dans la pile.");
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
	
	private boolean isOp�ration(String str) {
		if (str.length() != 1)
			return false;

		return this.renvoieOp�ration(str) != null;
	}

	private Op�ration renvoieOp�ration(String str) {
		for (Op�ration op : Op�ration.values())
			if (str.charAt(0) == op.getSymbole())
				return op;
		return null;

	}
}

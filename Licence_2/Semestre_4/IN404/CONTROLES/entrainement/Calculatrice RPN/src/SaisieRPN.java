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
		System.out.println("Entrez un nombre, un opération ou 'exit' pour quitter:");
		while (!sortie) {
			if (sc.hasNextDouble()) { // Double
				moteur.enregistrerDouble(sc.nextDouble());
				System.out.println(moteur.listerOpérandes());
				str = sc.nextLine(); // (aller à la ligne suivante après nextDouble)
			}
			else {
				str = sc.nextLine();
				if (this.isOpération(str)) // Opération
					if (moteur.opérationPossible()) {
						moteur.enregistrerAppliquerOpération(this.renvoieOpération(str));
						System.out.println(moteur.listerOpérandes());
					} 
					else
						System.out.println("Opération nécessite au moins 2 entiers dans la pile.");
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
	
	private boolean isOpération(String str) {
		if (str.length() != 1)
			return false;

		return this.renvoieOpération(str) != null;
	}

	private Opération renvoieOpération(String str) {
		for (Opération op : Opération.values())
			if (str.charAt(0) == op.getSymbole())
				return op;
		return null;

	}
}

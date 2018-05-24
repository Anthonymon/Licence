import exc.ValueException;

/*
 * CPOO IN404
 * Gestion d'erreurs et exceptions.
 * Cas d'erreurs:
 * MinValueException
 * MaxValueException
 */

/**
 * @author Maxime
 *
 */
public enum CalculatriceRPN {
	ENVIRONNEMENT;
	
	public void run(String[] args) {
		SaisieRPN srpn = new SaisieRPN();
		srpn.afficherValues();
		try {
			srpn.saisieCalculatrice();
		} catch (ValueException e) {
			System.out.println(e.getMessage());
			System.out.print("Arrêt du programme.");
		}
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		ENVIRONNEMENT.run(args);
	}

}

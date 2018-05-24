/**
 * @author Maxime
 * Normalement, public class MontantNegatifException extends Exception
 * Ici, j'utilise RuntimeException au lieu de Exception pour ne pas avoir
 * de messages d'erreur pour le constructeur et toutes les autres petites
 * fonctions si on n'ajoute pas throws.
 * IndexOutOfBoundsException est une exception héritant de RuntimeException.
 */

public class MontantNegatifException extends RuntimeException {

	public MontantNegatifException() {
		super("Le montant donné est négatif");
		// TODO Auto-generated constructor stub
	}

}

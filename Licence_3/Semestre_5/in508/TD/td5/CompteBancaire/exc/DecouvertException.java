/**
 * @author Maxime
 * Normalement, public class DecouvertException extends Exception
 * Ici, j'utilise RuntimeException au lieu de Exception pour ne pas avoir
 * de messages d'erreur pour le constructeur et toutes les autres petites
 * fonctions si on n'ajoute pas throws.
 * IndexOutOfBoundsException est une exception héritant de RuntimeException.
 */

public class DecouvertException extends RuntimeException {

	public DecouvertException() {
		super("L'opération implique que le compte soit à découvert");
		// TODO Auto-generated constructor stub
	}
}

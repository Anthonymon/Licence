package exceptions;

/**
 * @author Clement Caumes
 * @version 1.0
 * Exception MontantNegatifException
 */
public class MontantNegatifException extends RuntimeException{
	/**
	 * Constructeur de MontantNegatifException
	 */
	public MontantNegatifException() {
		super("Le montant donné est négatif");
	}
}

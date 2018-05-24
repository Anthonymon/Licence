package exceptions;

/**
 * @author Clement Caumes
 * @version 1.0
 * Exception DecouvertException
 */
public class DecouvertException extends RuntimeException{
	/**
	 * Constructeur de DecouvertException
	 */
	public DecouvertException() {
		super("Compte Bancaire a découvert");
	}
}

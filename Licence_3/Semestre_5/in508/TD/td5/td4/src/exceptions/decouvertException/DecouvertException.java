package exceptions.decouvertException;

/**
 * @author Clement Caumes
 * @version 1.0
 * Exception NegatifException
 */
public class DecouvertException extends RuntimeException {

	/**
	 * Constructeur DecouvertException
	 */
	public DecouvertException() {
		super("L'opération implique que le compte soit à découvert");
	}
}

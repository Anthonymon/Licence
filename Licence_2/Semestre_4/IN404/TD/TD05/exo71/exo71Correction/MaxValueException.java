

public class MaxValueException extends ValueException {
	
	public MaxValueException(double value) {
		super(value + " est sup�rieur � MAX_VALUE");
	}
}

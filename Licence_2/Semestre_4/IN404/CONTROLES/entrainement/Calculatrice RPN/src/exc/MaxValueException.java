package exc;

public class MaxValueException extends ValueException {
	
	public MaxValueException(double value) {
		super(value + " est supérieur à MAX_VALUE");
	}
}

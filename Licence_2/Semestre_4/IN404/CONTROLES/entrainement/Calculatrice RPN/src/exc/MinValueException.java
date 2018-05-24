package exc;

public class MinValueException extends ValueException {

	public MinValueException(double value) {
		super(value + " est inférieur à MIN_VALUE");
	}

}

public class MinValueException extends ValueException {

	public MinValueException(double value) {
		super(value + " est inf�rieur � MIN_VALUE");
	}

}

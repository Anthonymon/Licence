package fr.uvsq.hal.simpleshapes.shapes;

/**
 * A rectangle.
 *
 * @version sept. 2016
 * @author Stéphane Lopes
 */
public class Rectangle implements Shape {
	private Point upLeft;
	private Point downRight;

	/**
	 * Initialize the rectangle.
	 * 
	 * @param upLeft up left corner
	 * @param downRight down right corner
	 */
	public Rectangle(Point upLeft, Point downRight) {
		assert upLeft.getX() <= downRight.getX()
				&& upLeft.getY() >= downRight.getY();
		this.upLeft = upLeft;
		this.downRight = downRight;
	}

	/**
	 * Move the rectangle.
	 * 
	 * @param dx move in x
	 * @param dy move in y
	 */
	@Override
	public void translate(double dx, double dy) {
		upLeft.translate(dx, dy);
		downRight.translate(dx, dy);
	}

	/**
	 * Get a String description of the rectangle.
	 * 
	 * @return the String description
	 */
	@Override
	public String toString() {
		StringBuilder str = new StringBuilder();
		str.append("[");
		str.append(upLeft.toString());
		str.append(", ");
		str.append(downRight.toString());
		str.append("]");
		return str.toString();
	}
}

package fr.uvsq.hal.simpleshapes.shapes;

/**
 * A circle.
 *
 * @version sept. 2016
 * @author Stéphane Lopes
 */
public class Circle implements Shape {
	private Point center;
	private double radius;

	/**
	 * Initialize with center and radius.
	 * 
	 * @param center the center
	 * @param radius the radius
	 */
	public Circle(Point center, double radius) {
		this.center = center;
		this.radius = radius;
	}

	/**
	 * Get the radius of the circle.
	 * 
	 * @return the radius
	 */
	public double getRadius() {
		return radius;
	}

	/**
	 * Move the circle.
	 *
	 * @param dx x move
	 * @param dy y move
	 */
	@Override
	public void translate(double dx, double dy) {
		center.translate(dx, dy);
	}

	/**
	 * Gives a String representation of the circle.
	 * 
	 * @return the string representation
	 */
	@Override
	public String toString() {
		StringBuilder str = new StringBuilder();
		str.append('[');
		str.append(center.toString());
		str.append(", ");
		str.append(radius);
		str.append(']');
		return str.toString();
	}
}

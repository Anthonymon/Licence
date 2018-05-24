package fr.uvsq.hal.simpleshapes.shapes;

/**
 * A 2 dimensional point.
 *
 * @version sept. 2016
 * @author Stéphane Lopes
 */
public class Point {
	private double x;
	private double y;

	/**
	 * Initialize from 2 coordinates.
	 * 
	 * @param x x coordinate
	 * @param y y coordinate
	 */
	public Point(double x, double y) {
		this.x = x;
		this.y = y;
	}

	/**
	 * Get X coordinate.
	 * 
	 * @return X coordinate
	 */
	public double getX() {
		return x;
	}

	/**
	 * Get Y coordinate.
	 *
	 * @return Y coordinate
	 */
	public double getY() {
		return y;
	}

	/**
	 * Move the point.
	 * 
	 * @param dx move in x
	 * @param dy move in y
	 */
	public void translate(double dx, double dy) {
		x += dx;
		y += dy;
	}

	/**
	 * String description of the point.
	 * 
	 * @return the String description
	 */
    @Override
	public String toString() {
		StringBuilder str = new StringBuilder();
		str.append('(');
		str.append(x);
		str.append(", ");
		str.append(y);
		str.append(')');
		return str.toString();
	}
}

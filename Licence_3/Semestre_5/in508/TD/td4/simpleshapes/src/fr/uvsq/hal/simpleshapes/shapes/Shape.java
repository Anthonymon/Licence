package fr.uvsq.hal.simpleshapes.shapes;

/**
 * A shape.
 *
 * @version sept. 2016
 * @author Stéphane Lopes
 */
public interface Shape {
	/**
	 * Move the shape.
	 * 
	 * @param dx x move
	 * @param dy y move
	 */
	void translate(double dx, double dy);
}

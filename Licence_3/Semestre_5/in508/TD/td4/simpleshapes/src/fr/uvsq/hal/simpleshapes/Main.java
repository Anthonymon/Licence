package fr.uvsq.hal.simpleshapes;

import fr.uvsq.hal.simpleshapes.shapes.Circle;
import fr.uvsq.hal.simpleshapes.shapes.Point;
import fr.uvsq.hal.simpleshapes.shapes.Rectangle;
import fr.uvsq.hal.simpleshapes.shapes.Shape;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

import java.util.ArrayList;
import java.util.List;

/**
 * Very simple drawing app.
 * The program is just a small example of shape method invocation.
 * 
 * @version sept. 2016
 * @author Stéphane Lopes
 */
public enum Main {
	ENVIRONNEMENT;

	private static Log log = LogFactory.getLog("fr.uvsq.hal.simpleshapes");

	/**
	 * Main method.
	 * 
	 * @param args command line arguments
	 */
	public void run(String[] args) {
		log.info("SimpleShapes started");
		List<Shape> shapes = /*new ArrayList<>()*/null;

		shapes.add(new Rectangle(new Point(0.0, 5.0), new Point(2.0, 2.0)));
		shapes.add(new Circle(new Point(1.0, 2.0), 3.0));
		shapes.add(new Rectangle(new Point(5.0, 5.0), new Point(7.0, 3.0)));
		shapes.add(new Circle(new Point(4.0, 5.0), 2.0));
		log.trace(shapes);

		for (Shape s : shapes) {
			s.translate(1.0, 2.0);
		}

		log.trace(shapes);
		log.info("SimpleShapes exited");
	}

	public static void main(String[] args){
		ENVIRONNEMENT.run(args);
	}
}
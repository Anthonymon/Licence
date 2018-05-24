package main;
import compteBancaire.CompteBancaire;

/**
 * @author Clement Caumes
 * @version 1.0
 * Main du projet CompteBancaire
 */
public class Main {

	/**
	 * Methode Principale
	 * @param args parametre a mettre en arguments
	 */
	public static void main(String[] args) {
		CompteBancaire c=new CompteBancaire(12);
		System.out.println(c.getSolde());
	}

}

//package main;
package fr.uvsq.ClementCaumes.tdmaven;

//import compteBancaire.*;

/**
 * @author Clement Caumes
 * @version 1.0
 * Main du projet Compte Bancaire
 */
public class Main {

	/**
	 * Methode principale
	 * @param args parametre a mettre en arguments
	 */
	public static void main(String[] args) {
		CompteBancaire c=new CompteBancaire(12);
		System.out.println(c.getSolde());

	}

}

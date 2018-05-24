package compteBancaire;
import exceptions.*;

/**
 * @author Clement Caumes
 * @version 1.0
 * Classe CompteBancaire qui représente un compte en banque
 */
public class CompteBancaire {
	/**
	 * Solde représentant l'argent dans la classe CompteBancaire
	 */
	private double solde;
	
	/**
	 * Constructeur sans parametre de CompteBancaire
	 */
	public CompteBancaire() {
		this.solde=0;
	}
	
	/**
	 * Constructeur avec solde en parametre de CompteBancaire
	 * @param solde somme initial dans le CompteBancaire cree
	 */
	public CompteBancaire(double solde) {
		if(solde<0) throw new MontantNegatifException();
		this.solde=solde;
	}
	
	/**
	 * Accesseur du solde de CompteBancaire
	 * @return double qui représente le solde du CompteBancaire
	 */
	public double getSolde() {
		return this.solde;
	}
	
	/**
	 * Setteur du solde de CompteBancaire
	 * @param solde somme a initialiser dans CompteBancaire
	 */
	public void setSolde(double solde) {
		if(solde<0) throw new MontantNegatifException();
		this.solde=solde;
	}
	
	/**
	 * Methode Credit de CompteBancaire
	 * @param montant somme a crediter du solde 
	 * @exception jete l'exception MontantNegatifException si le montant est negatif
	 */
	public void credit(double montant) {
		if(montant<0) throw new MontantNegatifException();
		this.solde+=montant;
	}
	
	/**
	 * Methode Debit de CompteBancaire
	 * @param montant somme a debiter du solde
	 * @exception jete l'exception MontantNegatifException si le montant est negatif
	 * @exception jete l'exception DecouvertException si le solde est à decouvert
	 */
	public void debit(double montant) {
		if(montant<0) throw new MontantNegatifException();
		if(this.solde-montant<0) throw new DecouvertException();
		
		this.solde-=montant;
	}
}

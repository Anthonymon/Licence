package compteBancaire;

import exceptions.decouvertException.DecouvertException;
import exceptions.negatifException.*;

/**
 * @author Clement Caumes
 * @version 1.0
 * CompteBancaire supporte l'initialisation avec un solde initial,
 *  la consultation du solde,
 * le crédit, le débit et le virement vers un autre compte
 */
public class CompteBancaire {
	/**
	 * solde : entier qui correspond au solde du compte bancaire
	 */
	private int solde;

	/**
	 * Constructeur de la classe CompteBancaire
	 * @param solde solde à initialisé dans le compteBancaire nouvellement créé
	 */
	public CompteBancaire(int solde) {
		if (solde < 0) throw new DecouvertException();
		this.solde = solde;
	}

	/**
	 * Accesseur de l'attribut solde
	 * @return solde qui est l'attribut de CompteBancaire
	 */
	public int getSolde() {
		return solde;
	}
	
	/**
	 * Methode qui ajoute montant dans CompteBancaire
	 * @param montant entier à créditer sur le CompteBancaire
	 */
	public void crediteSolde(int montant) {
		if (montant < 0) throw new NegatifException();
		montant = Math.abs(montant);
		this.solde += montant;
	}
	
	/**
	 * Methode qui debite un solde dans CompteBancaire
	 * @param montant entier a debiter sur le CompteBancaire
	 */
	public void debiteSolde(int montant) {
		if (montant < 0) throw new NegatifException();
		if (this.solde - montant < 0) throw new DecouvertException();
		montant = Math.abs(montant);
		this.solde -= montant;
	}
	
	/**
	 * Methode de virement du CompteBancaire vers un autre
	 * @param montant a virer 
	 * @param receveur CompteBancaire du virement
	 * @exception si le montant est negatif MontantNegatifException
	 * @exception si le virement est trop élevé DecouvertException
	 */
	public void virement(int montant, CompteBancaire receveur) {
		if (montant < 0) throw new NegatifException();
		if (this.solde - montant < 0) throw new DecouvertException();
		receveur.crediteSolde(montant);
		this.debiteSolde(montant);
	}
}

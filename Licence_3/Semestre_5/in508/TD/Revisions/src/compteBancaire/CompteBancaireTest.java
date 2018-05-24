package compteBancaire;
import exceptions.*;

import static org.junit.Assert.*;

import org.junit.Test;

/**
 * 
 * @author Clement Caumes
 * @version 1.0
 * Classe CompteBancaireTest qui fait les tests JUnit
 */
public class CompteBancaireTest {

	/**
	 * Fonction qui teste si le montant est negatif avec une initialisation a -12
	 */
	@Test(expected=MontantNegatifException.class)
	public void testMontantNegatif() {
		CompteBancaire c=new CompteBancaire(-12);
	}
	
	/**
	 * Fonction qui teste si le compte est a decouvert 
	 */
	@Test(expected=DecouvertException.class)
	public void testCompteDecouvert() {
		CompteBancaire c=new CompteBancaire(23);
		c.debit(50);
	}

}

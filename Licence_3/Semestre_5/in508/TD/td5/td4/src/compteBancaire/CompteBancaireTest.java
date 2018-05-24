package compteBancaire;

import static org.junit.Assert.*;
import exceptions.decouvertException.*;
import exceptions.negatifException.*;
import org.junit.Test;

/**
 * @author Clement Caumes
 * @version 1.0
 * CompteBancaireTest correspond aux tests jUnit de CompteBancaire
 */
public class CompteBancaireTest {

	/**
	 * Teste si c'est non null
	 */
	@Test
	public void testNotNull() {
		CompteBancaire cpte = new CompteBancaire(1);
		assertNotNull(cpte);
	}
	
	/**
	 * Teste si le solde vaut une certaine valeur
	 */
	@Test
	public void testSolde() {
		CompteBancaire cpte = new CompteBancaire(3);
		int solde1 = cpte.getSolde();
		assertEquals(3,solde1);
	}
	
	/**
	 * Teste si le solde est superieur a 0
	 */
	@Test(expected=DecouvertException.class)
	public void testSuperieurSolde() {
		CompteBancaire cpte = new CompteBancaire(-3);
	}
		
	/**
	 * Teste si le credit vaut une certaine valeur
	 */
	@Test
	public void testCredit() {
		CompteBancaire cpte = new CompteBancaire(3);
		cpte.crediteSolde(1);
		assertEquals(4, cpte.getSolde());
	}
	
	/**
	 * Teste si le credit est negatif
	 */
	@Test(expected=NegatifException.class)
	public void testCreditNegatif() {
		CompteBancaire cpte = new CompteBancaire(3);
		cpte.crediteSolde(-1);
	}
	
	/**
	 * Teste si le solde apres un debit est egal a une certaine valeur
	 */
	@Test
	public void testDebit() {
		CompteBancaire cpte = new CompteBancaire(3);
		cpte.debiteSolde(1);
		assertEquals(2, cpte.getSolde());
	}
	
	/**
	 * Teste si le solde nest pas negatif
	 */
	@Test(expected=NegatifException.class)
	public void testDebitNegatif() {
		CompteBancaire cpte = new CompteBancaire(3);
		cpte.debiteSolde(-1);
	}
	
	/**
	 * Test 1
	 */
	@Test(expected=DecouvertException.class)
	public void testDebitSuperieurSolde() {
		CompteBancaire cpte = new CompteBancaire(3);
		cpte.debiteSolde(5);
	}	
	
	/**
	 * Test 2
	 */
	@Test
	public void testVirement() {
		CompteBancaire cpte1 = new CompteBancaire(300);
		CompteBancaire cpte2 = new CompteBancaire(800);
		cpte1.virement(100, cpte2);
		cpte2.virement(300, cpte1);
		assertEquals(500, cpte1.getSolde());
		assertEquals(600, cpte2.getSolde());
	}
	
	/**
	 * Test 3
	 */
	@Test(expected=NegatifException.class)
	public void testVirementNegatif(){
		CompteBancaire cpte1 = new CompteBancaire(300);
		CompteBancaire cpte2 = new CompteBancaire(800);
		cpte1.virement(-100, cpte2);
	}
	
	/**
	 * Test 4
	 */
	@Test(expected=DecouvertException.class)
	public void testVirementSuperieurSolde(){
		CompteBancaire cpte1 = new CompteBancaire(300);
		CompteBancaire cpte2 = new CompteBancaire(800);
		cpte1.virement(1000, cpte2);
	}

}

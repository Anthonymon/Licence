import static org.junit.Assert.*;

import org.junit.Test;

public class MainTest {

	@Test
	public void test_egalite() {
		CompteBancaire c=new CompteBancaire(100); //test egalite
		assertEquals(new Double(c.getSolde()),new Double(100.0)); 
	
	}
	
	@Test
	public void test_debit() {
		CompteBancaire c1=new CompteBancaire(100); //test solde inferieur a 0
		c1.debit(10.0);
		assertTrue(c1.getSolde()>0);
	}
	
	@Test
	public void test_somme_positive() {
		CompteBancaire c1=new CompteBancaire(100);
		double i;
		i=c1.debit(10.0);
		assertTrue(i>0);
	}
	
	@Test
	public void test_virement() {
		CompteBancaire c1=new CompteBancaire(100);
		CompteBancaire c2=new CompteBancaire(50);
		c2.virement(c1,45);
		assertTrue(c2.getSolde()>0);
	}

}

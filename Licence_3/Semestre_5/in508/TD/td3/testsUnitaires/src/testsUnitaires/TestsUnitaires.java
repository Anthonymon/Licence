package testsUnitaires;

import static org.junit.Assert.*;
import compteBancaire.CompteBancaire;
import exceptions.*;


import org.junit.Test;

public class TestsUnitaires {

	@Test (expected=SoldeInfZeroException.class)
	public void testValeurInfZero() throws SoldeInfZeroException {
			CompteBancaire c=new CompteBancaire(-12.0);
			//assertTrue(c.getSolde()>0);
		
	}

}

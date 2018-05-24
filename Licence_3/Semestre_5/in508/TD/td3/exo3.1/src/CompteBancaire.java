//import org.junit.*;
//import static org.junit.Assert.*;


public class CompteBancaire {
	public double solde;
	
	public double getSolde() {
		return this.solde;
	}
	
	public CompteBancaire(double solde) {
		this.solde=solde;
	}
	public void consulteSolde() {
		System.out.println("Solde: ");
		System.out.println(this.solde);
	}
	
	public double credit(double credit) {
		this.solde=this.solde+credit;
		return credit;
	}
	
	public double debit(double debit) {
		this.solde=this.solde-debit;
		return debit;
	}
	
	public void virement(CompteBancaire c,double transfert) {
			this.debit(transfert);
			c.credit(transfert);
	}
	
}

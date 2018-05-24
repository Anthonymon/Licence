package compteBancaire;
import exceptions.*;

public class CompteBancaire {
	private double solde;
	
	public CompteBancaire(){
		this.setSolde(0);
	}
	public CompteBancaire(double solde){
		if(solde<0) throw new SoldeInfZeroException("Pas de solde inferieur a 0");
		this.setSolde(solde);
	}
	public double getSolde() {
		return solde;
	}
	public void setSolde(double solde) {
		this.solde = solde;
	}
	public void credit(double credit){
		if(credit<0) throw new SoldeInfZeroException("Pas de credit inferieur a 0");
		this.setSolde(this.getSolde()+credit);
	}
}

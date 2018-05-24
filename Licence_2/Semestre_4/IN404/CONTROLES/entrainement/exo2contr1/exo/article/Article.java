package exo.article;
import exo.exceptions.negatifException.NegatifException;

public abstract class Article
{
    private int codeBarre;
    private int prixHT;

    public Article(int c,int p)throws NegatifException,ArithmeticException{
        this.codeBarre=c;
        if(p<0) throw new NegatifException("Erreur");
        else this.prixHT=p;
    }
    
    public abstract int calculTVA();
    
    public int getCodeBarre(){
        return this.codeBarre;
    }
    
    public int getPrixHT(){
        return this.prixHT;
    }
}

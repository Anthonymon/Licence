package exo.article.alimentaire;
import exo.article.Article;
import exo.exceptions.negatifException.NegatifException;

public class Alimentaire extends Article
{
    int datePeremption;

    /**
     * Constructor for objects of class Alimentaire
     */
    public Alimentaire(int c,int p,int d) throws NegatifException, ArithmeticException
    {
        super(c,p);
        this.datePeremption=d;
    }

    @Override
    public int calculTVA(){
        return (int)(super.getPrixHT()+(super.getPrixHT()*0.055));
    }
}

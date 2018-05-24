package exo.article.nonAlimentaire;
import exo.article.Article;
import exo.exceptions.negatifException.NegatifException;

public class NonAlimentaire extends Article
{

    /**
     * Constructor for objects of class NonAlimentaire
     */
    public NonAlimentaire(int c,int d)throws NegatifException,ArithmeticException
    {
        super(c,d);
    }

    @Override
    public int calculTVA(){
        return (int)(super.getPrixHT()+(super.getPrixHT()*0.2));
    }
}

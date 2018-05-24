package monpackage.pile;
import monpackage.exceptions.*;

public class Pile
{
    private int sommet;
    private int taille;
    private Object[] contenu;

    public int getSommet(){
        return this.sommet;
    }
    
    public Object[] getContenu(){
        return this.contenu;
    }
    
    public Pile(int taille)
    {
        this.contenu=new Object[taille];
        this.sommet=0;
        this.taille=taille;
    }

    public void empile(Object o)throws PileVideException,PilePleineException{
        if(this.sommet==this.taille) throw new PilePleineException();
        this.contenu[sommet]=o;
        this.sommet++;
    }
    
    public Object depile()throws PileVideException,PilePleineException{
        if(this.sommet==0) throw new PileVideException();
        Object o=this.contenu[sommet];
        this.sommet--;
        return o;
    }
}

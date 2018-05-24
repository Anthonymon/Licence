import exceptions.*;

public abstract class Donneur
{
    protected String groupeSanguin;
    protected String rhesus;
    protected int dateNaissance;
    protected String nom;
    protected int poids;
    
    public Donneur(String g,String r,int d,String n,int p) throws GroupeSanguinException,RhesusException,PoidsException{
        if((g!="A")&&(g!="B")&&(g!="AB")) throw new GroupeSanguinException( "erreur1");
        if((r!="+")&&(r!="-")) throw new RhesusException("erreur2");
        if(p<0) throw new PoidsException("erreur3");
        this.groupeSanguin=g;
        this.rhesus=r;
        this.dateNaissance=d;
        this.nom=n;
        this.poids=p;
    }
    
    public int getWeight(){
        return this.poids;
    }
    
    public void updateWeight(int newWeight)
    {
        this.poids=newWeight;
    }
    
    public abstract boolean donPossible();
}

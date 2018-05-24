package in404;
import in404.client.Client;
import in404.serveur.Serveur;

/**
 * Write a description of class main here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public abstract class main
{
    // instance variables - replace the example below with your own

    /**
     * Constructor for objects of class main
     */
    public main()
    {
        Client c1=new Client("clement");
        Client c2=new Client("yassin");
        Serveur s=new Serveur();
        c1.seConnecter(s);
        c2.seConnecter(s);
        c1.envoyer("zbeub zbeub");
        //c2.recevoir()
    }

}

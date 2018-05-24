package monpackage;
import monpackage.exceptions.*;
import monpackage.pile.Pile;

public enum Main
{
   ENVIRONNEMENT;
   
   public void run(){
       try{
           Pile p=new Pile(2);
           p.empile("a");
           p.empile("b");
           p.empile("c");
           //p.depile();
           p.empile("d");
        }
        catch(PilePleineException e){
           System.out.println("Pile PLEINE");
        }
        catch(PileVideException e){
            System.out.println("Pile VIDE");
        }
   }
    
   public static void main(){
    ENVIRONNEMENT.run();   
   }
}

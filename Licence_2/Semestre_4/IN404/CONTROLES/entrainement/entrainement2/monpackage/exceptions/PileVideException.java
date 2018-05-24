package monpackage.exceptions;


/**
 * Write a description of class PileVideException here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class PileVideException extends PileException
{
    public PileVideException(){
        super("La pile est vide");
    }
}

/**
 * La classe <code>Employe</code> représente les employés d'une entreprise.
 * 
 * @author Stéphane Lopes
 * @version jan. 2015
 */
public class Employe {
    /** Le nom de l'employé */
    private String nom;
    
    /** Le prenom de l'employé */
    private String prenom;
    
    /**L'age de l'employe */
    private int age;
    
    /**
     * Initialise un employé avec un prénom et un nom.
     * 
     * @param prenom le prénom de l'employé
     * @param nom    le nom de l'employé
     * @param age    l'age de l'employé
     */
    public Employe(final String prenom, final String nom, int age) {
        this.prenom = prenom;
        this.nom = nom;
        this.age = age;
    }
    
    /**
     * Retourne une chaîne de caractères représentant l'employé.
     * Le format utilisé est "nom prénom".
     * 
     * @return une chaîne contenant le prénom suivi du nom de l'employé
     */
    @Override
    public String toString() {
        return prenom + " " + nom + " " + age;
    }
    
}

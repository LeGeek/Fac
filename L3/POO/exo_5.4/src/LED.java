/**
 * Created by legeek on 05/11/14.
 */
public class LED extends Composant {

    private String nom;

    public LED( String nom ){
        this.nom = nom;
    }

    @Override
    void miseAJour() {
        if( entrees[0] == null || entrees[0].valeur == -1)
            return;
        else if( entrees[0].valeur == 1 )
            System.out.println("La LED " + nom + " est allumée");
        else
            System.out.println("La LED " + nom + " est éteinte");
    }
}

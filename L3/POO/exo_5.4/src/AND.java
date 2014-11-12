/**
 * Created by legeek on 22/10/14.
 */
public class AND extends Composant {

    @Override
    void miseAJour() {
        if( entrees[0] == null || entrees[1] == null || entrees[0].valeur == -1 || entrees[1].valeur == -1 )
            valeur = -1;
        else if( entrees[0].valeur == 1 && entrees[1].valeur == 1 )
            valeur = 1;
        else
            valeur = 0;

        propager();
    }
}

/**
 * Created by legeek on 05/11/14.
 */
public class OR extends Composant{

    @Override
    void miseAJour() {
        if( entrees[0] == null || entrees[1] == null || entrees[0].valeur == -1 || entrees[1].valeur == -1 )
            valeur = -1;
        else if( entrees[0].valeur == 1 || entrees[1].valeur == 1 )
            valeur = 1;
        else
            valeur = 0;

        propager();
    }
}

/**
 * Created by legeek on 05/11/14.
 */
public class NOT extends Composant {
    @Override
    void miseAJour() {
        if( entrees[0] == null )
            valeur = -1;
        else if( entrees[0].valeur != 1 )
            valeur = 0;
        else
            valeur = 1;

        propager();
    }
}

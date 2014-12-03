/**
 * Created by legeek on 03/12/14.
 */
public class EvenementSouris implements Evenement {

    public enum BoutonSouris { AUCUN, DROIT, GAUCHE, MILIEU };

    int x;
    int y;
    BoutonSouris bouton;

    public EvenementSouris( int x, int y, BoutonSouris bouton ){
        super();

        this.x = x;
        this.y = y;
        this.bouton = bouton;
    }

    @Override
    public void afficher() {
        System.out.println( "Souris : " + bouton + " (" + x + "; " + y + ")" );
    }
}

/**
 * Created by legeek on 15/10/14.
 */
public class Barreau {
    // Ne pas faire hériter de Plaque, sinon on se frappe la découpe dans un sens que l'on ne veux pas. CQFD / QED
    public final static int LARGEUR_PLAQUE = 3;
    private Plaque plaque;

    Barreau( int longueur ){
        plaque = new Plaque( longueur, LARGEUR_PLAQUE );
    }

    Barreau( Plaque p ){
        plaque = p;
    }

    Plaque découperSensLargeur( int cm ){
        return plaque.decouperSensLargeur( cm );
    }

    boolean conforme(){
        return ( plaque.getLargeur() == LARGEUR_PLAQUE );
    }

    int getLongueur() {
        return plaque.getLongueur();
    }
}

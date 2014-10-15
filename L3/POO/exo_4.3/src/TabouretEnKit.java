/**
 * Created by legeek on 15/10/14.
 */
public class TabouretEnKit {
    Plaque plaque;
    Barreau barreau[];

    TabouretEnKit( Plaque p, Barreau b1, Barreau b2, Barreau b3, Barreau b4){
        plaque = p;
        barreau = new Barreau[]{ b1, b2, b3, b4 };
    }

    int largeur(){
        return plaque.getLargeur();
    }

    int hauteur() {
        int max = barreau[0].getLongueur();

        for( int i = 0; i < barreau.length; ++i)
            if( max > barreau[i].getLongueur() )
                max = barreau[i].getLongueur();

        return max;
    }

    boolean conforme() {
        if( plaque.getLargeur() != plaque.getLongueur() )
            return false;

        for( int i = 1; i < barreau.length; ++i)
            if( barreau[i-1].getLongueur() != barreau[i].getLongueur() )
                return false;

        return true;
    }
}

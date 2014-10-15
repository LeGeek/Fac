/**
 * Created by legeek on 15/10/14.
 */
public class Plaque {
    private int longueur;
    private int largeur;

    Plaque( int a, int b ){
        if( a > b) {
            longueur = a;
            largeur = b;
        }
        else{
            longueur = b;
            largeur = a;
        }
    }

    Plaque decouperSensLongueur( int cm ){
        if( cm >= largeur )
            return null;

        largeur -= cm;
        return new Plaque( longueur, cm );
    }

    Plaque decouperSensLargeur( int cm ){
        if( cm >= longueur )
            return null;

        longueur -= cm;

        Plaque tmp = new Plaque( cm, largeur );

        if( longueur < largeur ) {
            int t = longueur;
            longueur = largeur;
            largeur = t;
        }

        return tmp;
    }

    public int getLongueur() {
        return longueur;
    }

    public int getLargeur() {
        return largeur;
    }
}

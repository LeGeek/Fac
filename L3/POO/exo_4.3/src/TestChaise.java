/**
 * Created by legeek on 15/10/14.
 */
public class TestChaise {
    public static void main(String[] args) {
        Plaque plaque = new Plaque( 50, 122 );

        Plaque dossier = plaque.decouperSensLargeur( 60 );
        Plaque assise = plaque.decouperSensLargeur( 50 );

        Barreau pied1 = new Barreau( plaque.decouperSensLongueur(3) );
        Barreau pied2 = new Barreau( plaque.decouperSensLongueur(3) );
        Barreau pied3 = new Barreau( plaque.decouperSensLongueur(3) );
        Barreau pied4 = new Barreau( plaque );

        ChaiseEnKit chaise = new ChaiseEnKit(dossier, assise, pied1, pied2, pied3, pied4);
        System.out.println( "Largeur : " + chaise.largeur() );
        System.out.println( "Hauteur : " + chaise.hauteur() );
        System.out.println( "Conforme : " + (chaise.conforme() ? "OUI" : "NON") );
    }
}

/**
 * Created by legeek on 24/09/14.
 */
public class screwdriver {
    public static void main( String[] args){
        Bouteille vodka = new Bouteille( 100 );
        Bouteille orange = new Bouteille( 100 );
        Verre verre = new Verre( 20 );

        vodka.ouvrir();
        orange.ouvrir();

        vodka.verser_dans( verre, 5);
        orange.verser_dans( verre, 10);

        vodka.fermer();
        orange.fermer();

        verre.boire( 20 );
    }
}

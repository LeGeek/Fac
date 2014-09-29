/**
 * Created by legeek on 24/09/14.
 */
public class Main {
    public static void main( String[] args ) {
        try {
            ListeEntier listeEntier = new ListeEntier();

            listeEntier.ajoute( 7 );
            listeEntier.ajoute( 654 );
            listeEntier.ajoute( 23 );
            listeEntier.ajoute( 64 );
            listeEntier.ajoute( 2 );
            listeEntier.ajoute( 68 );
            listeEntier.ajoute( 647 );
            listeEntier.ajoute( 98 );
            listeEntier.ajoute( 9846 );
            listeEntier.ajoute( 97 );
            listeEntier.ajoute( 0 );

            System.out.println( "Taille liste : " + listeEntier.longueur() );
            listeEntier.enleve();
            listeEntier.enleve();
            System.out.println( "Taille liste : " + listeEntier.longueur() );
            System.out.println( "Entier min de la liste : " + listeEntier.minimum() );
            listeEntier.ajoute( 1 );
            System.out.println( "Taille liste : " + listeEntier.longueur() );
            System.out.println( "Entier min de la liste : " + listeEntier.minimum() );
        }
        catch (ListeException e) {
            System.err.println(e.getMessage());
        }
    }
}

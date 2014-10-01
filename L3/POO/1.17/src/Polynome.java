import java.util.ArrayList;

/**
 * Created by legeek on 01/10/14.
 */
public class Polynome {
    ArrayList<Monome> list;

    Polynome( float coeff, int degre ){
        list = new ArrayList<Monome>();

        for(int i = 0; i < degre; ++i){
            list.add( new Monome( 0, i) );
        }

        list.add( new Monome( coeff, degre ) );
    }

    void additionne( float coeff, int degre ){
        additionne( new Monome( coeff, degre) );
    }

    void additionne( Monome m )
    {
        for( int i = 0; i < list.size(); ++i ){
            list.get(i).additionne( m );
        }
    }

    void multiplie( float coeff, int degre ){
        multiplie( new Monome( coeff, degre ) );
    }

    void multiplie( Monome m ){
        for( int i = 0; i < list.size(); ++i){
            list.get(i).multiplie(m);
        }
    }

    void affiche(){
        for( int i = 0; i < list.size() - 1; ++i){
            list.get(i).affiche();
            System.out.print(" + ");
        }

        list.get( list.size() - 1 ).affiche();
        System.out.println();
    }
}

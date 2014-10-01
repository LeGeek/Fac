/**
 * Created by legeek on 01/10/14.
 */
public class Monome {
    private float coeff;
    private int degre;

    Monome( float coeff, int degre ){
        this.coeff = coeff;
        this.degre = degre;
    }

    float getCoeff() { return coeff; }
    int getDegre(){ return  degre; }

    void additionne( float coeff){
        this.coeff += coeff;
    }

    void additionne( Monome m ){
        if( m.getDegre() != degre )
            return;

        additionne( m.getCoeff() );
    }

    void multiplie( float coeff, int degre ){
        this.coeff *= coeff;
        this.degre += degre;
    }

    void multiplie( Monome m ){
        multiplie( m.coeff, m.degre );
    }

    void affiche(){
        if( coeff == 0.0 )
            System.out.print( "x^" + degre );
        else if( degre == 0 )
            System.out.print( coeff );
        else
            System.out.print(coeff + "x^" + degre);
    }
}

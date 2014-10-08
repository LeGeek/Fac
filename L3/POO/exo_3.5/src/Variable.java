/**
 * Created by legeek on 08/10/14.
 */
public class Variable implements ExpressionBooleenne {
    private boolean variable;

    public Variable( boolean val ){
        variable = val;
    }

    public void setValeur( boolean val ){
        variable = val;
    }

    @Override
    public void affiche() {
        if( variable )
            System.out.print( "VRAI" );
        else
            System.out.print( "FAUX" );
    }

    @Override
    public boolean evalue() {
        return variable;
    }
}

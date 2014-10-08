/**
 * Created by legeek on 08/10/14.
 */
public class Non implements ExpressionBooleenne {

    private ExpressionBooleenne expressionBooleenne;

    public Non( ExpressionBooleenne e ){
        expressionBooleenne = e;
    }

    @Override
    public boolean evalue() {
        return !expressionBooleenne.evalue();
    }

    @Override
    public void affiche() {
        System.out.print( "NON(");
        expressionBooleenne.affiche();
        System.out.print( ")" );
    }
}

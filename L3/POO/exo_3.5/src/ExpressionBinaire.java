/**
 * Created by legeek on 08/10/14.
 */
public class ExpressionBinaire implements ExpressionBooleenne {

    ExpressionBooleenne e1, e2;
    OperateurBinaire op;

    public ExpressionBinaire( ExpressionBooleenne e1, OperateurBinaire op, ExpressionBooleenne e2){
        this.e1 = e1;
        this.e2 = e2;
        this.op = op;
    }

    @Override
    public boolean evalue() {
        return op.applique(e1.evalue(), e2.evalue());
    }

    @Override
    public void affiche() {
        System.out.print( "(" );
        e1.affiche();
        System.out.print(op.getName());
        e2.affiche();
        System.out.println( ")" );
    }

    public static void main(String[] args) {
        Variable v = new Variable(true);
        ExpressionBooleenne e = new ExpressionBinaire(new Non(v),
                new OperateurOu(),
                Constante.FAUX);
        e.affiche(); System.out.println(); // affiche (NON(VRAI) OU FAUX)
        System.out.println(e.evalue()); // affiche : false
        v.setValeur(false);
        System.out.println(e.evalue()); // affiche : true
    }
}

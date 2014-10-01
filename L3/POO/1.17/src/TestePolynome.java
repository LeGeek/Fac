/**
 * Created by legeek on 01/10/14.
 */
public class TestePolynome {
    public static void main(String[] args) {
        Polynome polynome = new Polynome( 6.1f, 2);

        polynome.additionne( 5.9f, 1);
        polynome.additionne( 3.6f, 0);

        polynome.affiche();

        polynome.multiplie(2f, 3);

        polynome.affiche();
    }
}

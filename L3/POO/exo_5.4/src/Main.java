/**
 * Created by legeek on 05/11/14.
 */
public class Main {
    public static void main(String[] args) {
        AND et = new AND(); OR ou = new OR();
        UN un = new UN(); ZERO zero = new ZERO();
        NOT non = new NOT();
        LED led1 = new LED("1"); LED led2 = new LED("2");
        et.raccorde(new Extremite(ou, 0));
        et.raccorde(new Extremite(non));
        non.raccorde(new Extremite(led1));
        un.raccorde(new Extremite(et, 0));
        un.raccorde(new Extremite(et, 1));
        // provoque l’affichage que la led 1 est eteinte:
        zero.raccorde(new Extremite(ou, 1));
        ou.raccorde(new Extremite(led2));
        zero.raccorde( new Extremite( et, 1) );
        // provoque l’affichage que la led 2 est allumee:
    }
}

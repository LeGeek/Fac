/**
 * Created by legeek on 03/12/14.
 */
public class EvenementClavier implements Evenement {

    private char c;

    public EvenementClavier( char c ){
        super();
        this.c = c;
    }

    @Override
    public void afficher() {
        System.out.println( "Clavier : " + c );
    }
}

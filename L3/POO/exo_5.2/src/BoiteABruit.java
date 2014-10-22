/**
 * Created by legeek on 22/10/14.
 */
public abstract class BoiteABruit {
    private boolean isUp;

    BoiteABruit(){
        isUp = true;
    }

    abstract String bruit();

    void retourne(){
        isUp = !isUp;

        if( isUp ){
            System.out.println( bruit() );
        }
    }
}

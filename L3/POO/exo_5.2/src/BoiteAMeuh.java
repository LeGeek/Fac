/**
 * Created by legeek on 22/10/14.
 */
public class BoiteAMeuh {
    boolean isUp;

    BoiteAMeuh(){
        isUp = true;
    }

    void retourne(){
        isUp = !isUp;

        if( isUp ){
            System.out.println( "Meuuuuhhhhh" );
        }
    }

    public static void main(String[] args) {
        BoiteAMeuh b = new BoiteAMeuh();

        for( int i = 0; i < 6; ++i )
            b.retourne();
    }
}

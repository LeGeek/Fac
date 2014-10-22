/**
 * Created by legeek on 22/10/14.
 */
public class BoiteAHihan extends BoiteABruit {

    @Override
    String bruit() {
        return "HiHannnnnn";
    }

    public static void main(String[] args) {
        BoiteAHihan b = new BoiteAHihan();

        for( int i = 0; i < 6; ++i )
            b.retourne();
    }
}

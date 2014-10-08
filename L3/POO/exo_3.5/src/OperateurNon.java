/**
 * Created by legeek on 08/10/14.
 */
public class OperateurNon implements OperateurBinaire {

    @Override
    public boolean applique(boolean e1, boolean e2) {
        return e1 && e2;
    }

    @Override
    public String getName() {
        return " ET ";
    }
}

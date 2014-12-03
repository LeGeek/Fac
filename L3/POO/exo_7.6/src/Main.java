import java.util.ArrayList;
import java.util.List;

/**
 * Created by legeek on 03/12/14.
 */
public class Main {
    public static void main(String[] args) {
        List<Evenement> evenements = new ArrayList<Evenement>();
        evenements.add(new EvenementSouris(10,10, EvenementSouris.BoutonSouris.GAUCHE));
        evenements.add(new EvenementClavier('a'));
        evenements.add(new EvenementClavier('z'));
        evenements.add(new EvenementSouris(40,20, EvenementSouris.BoutonSouris.AUCUN));
        for (Evenement e : evenements)
            e.afficher();
    }
}

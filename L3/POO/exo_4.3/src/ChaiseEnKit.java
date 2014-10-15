/**
 * Created by legeek on 15/10/14.
 */
public class ChaiseEnKit extends TabouretEnKit {
    Plaque dossier;

    ChaiseEnKit(Plaque dossier, Plaque assise, Barreau b1, Barreau b2, Barreau b3, Barreau b4) {
        super(assise, b1, b2, b3, b4);
        this.dossier = dossier;
    }

    @Override
    int largeur() {
        return super.largeur() + ( dossier.getLargeur() - super.largeur() );
    }

    @Override
    int hauteur() {
        return super.hauteur() + dossier.getLongueur();
    }

    @Override
    boolean conforme() {
        return super.conforme() &&
                dossier.getLargeur() == super.largeur();
    }
}

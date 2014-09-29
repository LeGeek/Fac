/**
 * Created by legeek on 24/09/14.
 */
public class CompteurCompose {
    private CompteurSimple compteur;
    private CompteurCompose compose;

    public CompteurCompose( CompteurSimple cpt ){
        compteur = cpt;
        compose = null;
    }

    public CompteurCompose( CompteurSimple cpt, CompteurCompose cmp ){
        compteur = cpt;
        compose = cmp;
    }

    public CompteurCompose( CompteurCompose cpt ){
        compteur = new CompteurSimple( cpt.getCompteur() );

        if( cpt.getCompose() != null )
            compose = new CompteurCompose( cpt.getCompose() );
    }

    public CompteurSimple getCompteur() {
        return compteur;
    }

    public CompteurCompose getCompose() {
        return compose;
    }

    public boolean inc(){
        if( compteur.inc() ){
            if( compose != null)
                compose.inc();

            return true;
        }

        return false;
    }

    public void affiche(){
        if( compose != null ){
            compose.affiche();
        }

        compteur.affiche();
    }

    public boolean equals( CompteurCompose toCompare ){
        if( compose != null ){
            return compteur.equals( toCompare.getCompteur() ) &&
                   compose.equals( toCompare.getCompose() );
        }
        else{
            return compteur.equals( toCompare.getCompteur() );
        }
    }
}

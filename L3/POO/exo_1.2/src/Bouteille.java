/**
 * Created by legeek on 24/09/14.
 */
public class Bouteille {
    private int quantite;
    private boolean est_ouvert;

    public Bouteille( int q ){
        quantite = q;
        est_ouvert = false;
    }

    public void ouvrir(){
        est_ouvert = true;
        System.out.println("Bouteille ouverte");
    }

    public void fermer(){
        est_ouvert = false;
        System.out.println("Bouteille fermé");
    }

    public void verser_dans( Verre v, int q){
        if( !est_ouvert )
            return;

        v.emplir( q );
        System.out.println("Bouteille vidée de " + q + " cl");
    }
}

/**
 * Created by legeek on 22/10/14.
 */
public class TicketPerso extends TicketRechargeable {
    private TicketSimple abonnement;

    TicketPerso(){
        super( 0 );
        abonnement = null;
    }

    boolean abonnement( int duree, float prix ){
        if( abonnement != null && abonnement.valide() )
            return false;

        abonnement = new TicketSimple( duree, prix );
        return true;
    }

    boolean valide(){
        if( abonnement != null ){
            if( abonnement.valide() )
                return true;
            else
                abonnement = null;
        }

        return super.valide();
    }


}

/**
 * Created by legeek on 15/10/14.
 */
public class TicketSimple {
    Date validite;
    int tempsValidite;
    float prix;

    TicketSimple( int tpsValid, float prix ){
        validite = null;
        tempsValidite = tpsValid;
        this.prix = prix;
    }

    float prix() {
        return prix;
    }

    boolean valide(){
        if( validite == null ){
            validite = Date.getMaintenant().plus( tempsValidite );
            return true;
        }

        return Date.getMaintenant().avant( validite );
    }
}

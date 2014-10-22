/**
 * Created by legeek on 15/10/14.
 */
public class TicketSimple {
    private Date validite;
    private int tempsValidite;
    private float prix;

    TicketSimple( int tpsValid, float prix ){
        validite = null;
        tempsValidite = tpsValid;
        this.prix = prix;
    }

    int tempsValidite() { return tempsValidite; }
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

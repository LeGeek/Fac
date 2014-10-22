/**
 * Created by legeek on 22/10/14.
 */
public class TicketRechargeable {
    private TicketSolo ticket;
    private int voyagesRestant;

    TicketRechargeable( int nb ){
        voyagesRestant = nb;
        ticket = new TicketSolo();
    }

    int reste() {
        return voyagesRestant;
    }

    void recharge( int n ){
        voyagesRestant += n;
    }

    boolean valide(){
        if( ticket.valide() ){
            return true;
        }
        else if( voyagesRestant > 0 ){
            --voyagesRestant;
            ticket = new TicketSolo();
            return ticket.valide();
        }

        return false;
    }
}

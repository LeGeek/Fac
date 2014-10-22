/**
 * Created by legeek on 22/10/14.
 */
public class TicketMultiple {
    private TicketRechargeable ticket;

    TicketMultiple( int voyage ){
        ticket = new TicketRechargeable( voyage );
    }

    boolean valide(){
        return ticket.valide();
    }
}

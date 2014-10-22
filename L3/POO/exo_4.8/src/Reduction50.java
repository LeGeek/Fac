/**
 * Created by legeek on 22/10/14.
 */
public class Reduction50 extends TicketSimple {

    Reduction50( TicketSimple ticket){
        super( ticket.tempsValidite(), ticket.prix()/2 );
    }

    public static void main(String[] args) {
        Date.setMaintenant(new Date(1002131548));
        TicketSimple t = new Reduction50( new Ticket1Jour() );
        t.valide();
        System.out.println( t.prix() );
    }
}

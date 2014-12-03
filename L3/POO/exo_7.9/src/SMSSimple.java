import java.util.Iterator;
import java.util.Stack;

/**
 * Created by legeek on 03/12/14.
 */
public class SMSSimple implements SMS {
    private String message;
    Stack< Character > pileChar;

    @Override
    public void ajouter(char c) {
        pileChar.push( c );
    }

    @Override
    public void supprimerPrecedent() {
        pileChar.pop();
    }

    @Override
    public char dernier() {
        return pileChar.peek();
    }

    @Override
    public void terminer() {
        message = "";
        for(Iterator it = pileChar.iterator(); it.hasNext(); ){
            message = (Character)it.next() + message;
            supprimerPrecedent();
        }
    }

    @Override
    public String message() {
        if( message == null )
            return "";
        else
            return message;
    }
}

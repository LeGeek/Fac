/**
 * Created by legeek on 24/09/14.
 */
public class ChainonEntier {
    int value;
    ChainonEntier next;

    public ChainonEntier( ChainonEntier c){
        value = c.value;
        next = c.next;
    }

    public ChainonEntier( int v, ChainonEntier n){
        value = v;
        next = n;
    }

    public void copie( ChainonEntier cp ){
        value = cp.value;
        next = cp.next;
    }
}

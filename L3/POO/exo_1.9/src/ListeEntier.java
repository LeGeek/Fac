/**
 * Created by legeek on 24/09/14.
 */
public class ListeEntier {
    private ChainonEntier head;

    public ListeEntier(){
        head = null;
    }

    public void ajoute( int value ){
        ChainonEntier c = new ChainonEntier( value, head );
        head = c;
    }

    public void enleve() throws ListeException {
        if( head == null )
            throw new ListeException("Il n'y a aucun élément dans la liste !");

        head = head.next;
    }

    public int longueur(){
        if( head == null )
            return 0;

        int i =0;
        ChainonEntier curseur = new ChainonEntier( head );

        while( curseur != null ){
            ++i;
            curseur = curseur.next;
        }

        return i;
    }

    public int minimum() throws ListeException{
        if( head == null )
            throw new ListeException("Il n'y a aucun élément dans la liste !");

        int min = head.value;
        ChainonEntier curseur = new ChainonEntier( head );

        while( curseur != null ){
            if( curseur.value < min )
                min = curseur.value;

            curseur = curseur.next;
        }

        return min;
    }

    public void copy( ListeEntier cp ) throws ListeException {
        if( cp.head == null )
            throw new ListeException("Il n'y a aucun élément dans la liste à copier !");

    }
}

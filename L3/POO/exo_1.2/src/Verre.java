/**
 * Created by legeek on 24/09/14.
 */
public class Verre {
    private int contenance;
    private int quantite;

    public Verre( int q ){
        quantite = q;
        contenance = 0;
    }

    public void emplir( int q ){
        if( contenance + q > quantite)
            contenance = quantite;
        else
            contenance += q;

        System.out.println( "Contenance du verre " + contenance + " cl");
    }

    public void boire( int q ){
        if( q > contenance )
            contenance = 0;
        else
            contenance -= q;

        System.out.println( "Contenance du verre " + contenance + " cl");
    }
}

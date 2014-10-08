/**
 * Created by legeek on 01/10/14.
 */
public class Vector {
    private int[] array;
    private int size;

    Vector()
    {
        array = new int[1];
        size = 0;
    }

    void ensureCapacity( int c ){
        if( size + c <= array.length)
            return;

        int[] tmp = new int[ Math.max( c, array.length*2) ];
        for( int i = 0; i < size; ++i)
            tmp[i] = array[i];

        for( int i = array.length; i < tmp.length; ++i )
            tmp[i] = 0;

        array = tmp;
    }

    void resize( int s ){
        ensureCapacity( s );
    }

    int size(){
        return size;
    }

    boolean isEmpty(){
        return (size == 0);
    }

    void add( int e ){
        ensureCapacity( 1 );
        array[ size++ ] = e;
    }

    void set( int i, int e ){
        if( i >= size )
            return;

        array[i] = e;
    }

    int get( int i ){
        if( i >= size )
            return 0;

        return array[i];
    }

    public static void main(String[] args) {
        Vector v = new Vector();
        v.add ( 0 );
        v.add( 156 );
        v.add( 34 );
        v.add( 458 );

        System.out.println( "Taille vecteur : " + v.size() );
        System.out.println( "Contenue du vecteur : ");
        for( int i = 0; i < v.size(); ++i)
            System.out.println( "\t" + v.get(i));

        v.set(0, 77);
        v.set(1, 77);
        System.out.println( "Contenue du vecteur : ");
        for( int i = 0; i < v.size(); ++i)
            System.out.println( "\t" + v.get(i));
    }
}

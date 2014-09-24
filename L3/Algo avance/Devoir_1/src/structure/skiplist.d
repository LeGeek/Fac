import std.container, std.conv, std.math, std.stdio;

import src.utils.randomcoin;
import src.structure.node;

class SkipList(T)
{
    private Node!(T) head;
    private int level;
    private RandomCoin alea;
    private long sizeList;
    private double proba;
    private Node!(T)[] insertPoint;

    this()
    {
        head = new Node!(T)( null, 32 );
        insertPoint = new Node!(T)[32];
        level = 0;
        alea = new RandomCoin();
        sizeList = 0;
        proba = 0.5;
    }

    public long size()
    {
        return sizeList;
    }

    public bool contains( T key )
    {
        return contains( level, new Node!T(head), key );
    }

    private bool contains( int lvl,  Node!T * cursor, T key )
    {
        if( cursor is null )
            return false;

        if( cursor.key == key)
            return true;

        if( cursor.next[lvl] is null || cursor.next[lvl].key > key )
        {
            if( lvl == 0)
                return false;

            return contains( lvl - 1, cursor, key);
        }

        return contains( lvl, cursor.next[lvl], key );
    }

    public void add( T key )
    {
        Node!T node = new Node!T( key, 32);
        //
        //for( int i = 0; i < 32; ++i)
        //{
        //    node.next[i] = head.next[i];
        //    head.next[i] = node;
        //}
        //
        //++sizeList;
        //level = to!int( log( to!(real)(sizeList) ) );
        
        add( level, new Node!T( head ), node );
    }

    private void add( int lvl, Node!T * cursor, Node!T * value )
    {
        //if( lvl == 0 && (cursor.next[0] is null || cursor.next[0].key > value.key ))
        //{
        //    //TODO : Ajout de l'élément ICI
        //}

        if( cursor.next[lvl].key is null || cursor.next[lvl].key > value.key )
        {
            add( lvl - 1, cursor, value );
        }
    }

    public void remove( T key )
    {
        //TODO
    }

    public Array!T toArray()
    {
        //TODO
        return Array!T();
    }
    
    override public string toString()
    {
        Node!T node = new Node!T( head.next[0] );
        string value = "";

        while( node !is null )
        {
            value ~= " " ~ to!(string)( node.key );
            node = node.next[0];
        }

        return value;
    }

}

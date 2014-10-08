import std.container, std.conv, std.math, std.stdio;

import src.utils.randomgenerator;
import src.structure.node;

class SkipList(T)
{
    private Node!T head;
    private int level;
    private RandomGenerator alea;
    private long sizeList;
    private double proba;
    private Node!(T)[32] insertPoint;

    this()
    {
        head = new Node!(T)( 0, 32 );
        level = 0;
        alea = new RandomGenerator();
        sizeList = 0;
        proba = 0.5;
        
        for( int i = 0; i < insertPoint.length; ++i )
            insertPoint[i] = head;
    }

    public long size()
    {
        return sizeList;
    }

    public bool contains( T key )
    {
        Node!T cursor = head.next[0];

        for(int lvl = level; lvl >= 0 && cursor !is null; )
        {
            if( cursor.key == key )
                return true;
            
            if( cursor.next[lvl] is null || cursor.next[lvl].key > key )
                --lvl;
            else
                cursor = cursor.next[lvl];
        }

        return false;
    }

    public void add( T key )
    {
        Node!T cursor = head;
        Node!T value = new Node!T( key, 32 );

        int lvl = level;
        while( lvl >= 0 && cursor.key != key )
        {
            if( cursor.next[lvl] is null || cursor.next[lvl].key > key )
            {
                insertPoint[lvl] = cursor;
                --lvl;
            }
            else
            {
                cursor = cursor.next[lvl];
            }

            --lvl;
        }
        
        int rnd = 1; 
        while( alea.flipCoin() && rnd < 31 )
            ++rnd;

        if( rnd > level )
            level = rnd;

        for( int i = 0; i < rnd; ++i )
        {
            value.next[i] = insertPoint[i].next[i];
            insertPoint[i].next[i] = value;

            insertPoint[i] = head;
        }
        
        ++sizeList;
    }

    public void remove( T key )
    {
        Node!T cursor = head.next[0];
        Node!T lastCursor = head;

        for( int lvl = level; lvl >= 0; )
        {
            if( cursor.next[lvl] is null || cursor.next[lvl].key > key )
            {
                --lvl;
            }
            else
            {
                lastCursor = cursor;
                cursor = cursor.next[lvl];
            }
        }

        if( cursor.key != key )
        {
            writeln( "Pas correspondance entre ", cursor.key, " et ", key );
            return;
        }

        int i = 0;
        do
        {
            lastCursor.next[i] = cursor.next[i];
            ++i;
        } while( cursor.next[i] !is null );


        --sizeList;
    }

    public T[] toList()
    {
        T[] tab;
        tab.length = sizeList;
        Node!T cursor = head.next[0];

        for( int i = 0; i < sizeList && cursor !is null; ++i )
        {
            tab[i] = cursor.key;
            cursor = cursor.next[0];
        }

        return tab;
    }
    
    override public string toString()
    {
        if( head.next[0] is null )
            return "\t/!\\ Aucun élément dans la liste. /!\\";

        Node!T node = head;
        string value = "";

        while( node !is null )
        {
            value ~= " " ~ to!(string)( node.key );
            node = node.next[0];
        }

        return value;
    }

}

class Node(T)
{
    public T key;
    public Node!T[] next;

    this(T value, int tabSize)
    {
        this.key = value;
        next = new Node!T[tabSize];
        
        for( int i = 0; i < tabSize; ++i)
        {
            next[i] = null;
        }
    }

    this( ref Node!T node )
    {
        this.key = node.key;
        this.next = node.next;
    }
}


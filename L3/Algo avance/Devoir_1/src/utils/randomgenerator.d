import std.random;

class RandomGenerator
{
    private Random rand;

    this()
    {
       this.rand.seed(unpredictableSeed);
    }

    public bool flipCoin()
    {
        return uniform(0, 2, rand) == 0 ? false : true;
    }

    public int next( int min, int max )
    {
        return uniform(min, max, rand);
    }
}

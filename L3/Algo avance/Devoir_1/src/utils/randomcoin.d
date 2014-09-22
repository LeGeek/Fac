import std.random;

class RandomCoin
{
    private Random rand;

    this()
    {
       this.rand.seed(unpredictableSeed);
    }

    public int flipCoin()
    {
        return uniform(0, 2, rand);
    }
}

inline Random::Random()
{
    srand( time( NULL ) );
}

inline Random::~Random() {}

inline int Random::flipCoin()
{
    return rand() % 2;
}

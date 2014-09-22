#include "random.h"
using namespace std;

Random::Random()
{
    srand( time( NULL ) );
}

Random::~Random()
{
}

int Random::next()
{
    return rand();
}
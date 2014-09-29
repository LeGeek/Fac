#include "bor-util.h"




int main( int argc, char** argv )
{
    (void) argc;
    (void) argv;

    int fdTube[2];
    pipe( fdTube );

    char c;
    for( int i = 0; i < 10; ++i )
    {
        printf( "Entrez un caractère : " );
        c = getchar();
        getchar();  //Absorbe the '\n'
        bor_write( fdTube[1], &c, 1 );
    }

    char buff[4];
    bor_read_str( fdTube[0], buff, 4 );
    printf( "Lecture des 3 premiers caractère : %s\n", buff );

    int p = fork();


    if( p == 0 )
    {
        close( fdTube[1] );

        char buff[8];
        bor_read_str( fdTube[0], buff, 8 );
        printf( "Lecture des 7 derniers caractères : %s\n", buff );
        close( fdTube[0] );
    }
    else
    {
        close( fdTube[0] );
        close( fdTube[1] );
    }

    return 0;
}

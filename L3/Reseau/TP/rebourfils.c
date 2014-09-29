#include "bor-util.h"

void compteRebour( int tps )
{
    if( tps <= 0 )
        return;

    while( tps > 0 )
    {
        fprintf( stdout, "[%d] : Temps restant : %d s\n", getpid(), tps);
        
        --tps;
        sleep( 1 );
    }
}

int main( int argc, char** argv )
{
    (void) argc;
    (void) argv;

    char buff[50];
    while( 1 )
    {
        printf( "Entrez un nombre : ");
        fgets( buff, sizeof(buff), stdin ); 
        
        if( !isdigit( buff[0] ) )
            continue;
        if( atoi( buff ) == 0 )
            break;


        for(int i = 0; i < atoi( buff ); ++i)
        {
            int p = fork();
            if( p == 0 ) //Fils
            {
                compteRebour( 10 );
                exit(0);
            }
        }
    }



    return 0;
}


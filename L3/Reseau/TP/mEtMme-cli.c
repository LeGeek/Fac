#include "bor-util.h"

#define MAX_NOM_SIZE    100

typedef struct
{
    char *tube_ec_nom, tube_cs_nom[MAX_NOM_SIZE], tube_sc_nom[MAX_NOM_SIZE];
    int tube_ec, tube_cs, tube_sc;
} Client;

int creer_tubes_service( Client * c )
{
    printf( "Création tubes dervices...\n" );
    sprintf( c->tube_cs_nom, "tube_cs_%d.tmp", (int) getpid() );
    int k = mkfifo( c->tube_cs_nom, 0600 );

    if( k < 0 )
    {
        perror( "mkfifo" );
        return -1;
    }

    k = mkfifo( c->tube_sc_nom, 0600 );
    if( k < 0 )
    {
        perror( "mkfifo" );
        unlink( c->tube_cs_nom );
        return -1;
    }

    return 0;
}

void supprimer_tubes_service( Client * c )
{
    printf( "Suppression tubes service" );
    unlink( c->tube_cs_nom );
    unlink( c->tube_sc_nom );
}

int ouvrir_tube_service( Client * c )
{
    printf( "Ouverture du tube : %s", c->tube_cs_nom );
    int k = open( c->tube_cs_nom, O_WRONLY );
    if( k < 0 )
    {
        perror( "open" );
        return -1;
    }

    printf( "Ouverture du tube : %s", c->tube_sc_nom );
    k = open( c->tube_sc_nom, O_RDONLY );
    if( k < 0 )
    {
        perror( "open" );
        return -1;
    }

    return 0;
}

int main( int argc, char** argv )
{
    (void) argc;
    (void) argv;

    return 0;
}

#include "bor-util.h"



int main( int argc, char** argv )
{
    int fd1[2];
    int fd2[2];

    pipe( fd1 );
    pipe( fd2 );

    int fils1 = fork();

    if( fils1 == 0 )    //Fils 1
    {
         close( fd1[0] );
         close( fd2[0] );
         close( fd2[1] );
         dup2( 0, fd1[1] );
    }
    else    // Pere | Fils 2
    {
        int fils2 = fork();
        if( fils2 == 0 )    //Fils 2
        {
            close( fd1[1] );
            close( fd2[0] );
            dup2( 1, fd1[0] );
            dup2( 0, fd2[1] );

        }
        else    //Pere
        {
            close( fd1[0] );
            close( fd1[1] );
            close( fd2[1] );
            dup2( 1, fd2[0] );
        }
    }

    return 0;
}

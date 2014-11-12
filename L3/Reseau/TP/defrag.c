// date-cli.c

#include "bor-util.h"

int dialoguer_avec_serveur(int soc)
{
	char  buf_out[1000];
	int k;
	printf("Lecture serveur ..\n");
	k = bor_read_str(soc,buf_out, sizeof(buf_out));
	if(k <= 0) return k;
	printf("Ecriture std ..\n");
	k = bor_write_str(0, buf_out);
	if(k <= 0) return k;	
	return k;
}

int detecter_ligne( char *buf, int pos, int fin )
{
    for( int i = pos; i < fin; ++i )
    {
        if(buf[i] == '\n')
        {
            buf[i] = '\0';
            return 1;
        }
    }

    return -1;
}

void supprimer_ligne( char * buf, int i, int * pos, int * fin )
{
    memmove( buf, buf+i+1, fin-i );
    *fin = i+1;
    *pos = 0;
}

void defragmenter_lignes( char * buf, int bufsize, int * pos )
{
    int i;
    while( (i = detecter_ligne( buf, *pos, fin )) >= 0 )
    {
        printf( "Détecte ligne : \"%s\"\n", buf);
        supprimer_ligne( buf, i, pos, &fin );
    }
    printf( "Reste dans buf : \"%s\"\n", buf );
    *pos = fin;

    if( *pos >= bufsize-1){
        printf( "Buffer plein, contenu supprimé\n" );
        *pos = 0;
        buf[0] = 0;
    }
}

int main(int argc, char* argv[])
{
    (void) argc;
    (void) argv;

    if(argc - 1 != 2)
    {
        fprintf(stderr, "Nombre d'argument invalide");
        return -1;
    }
    
    struct sockaddr_un adr_client;
    
    char *nom_serveur = argv[1];

    int soc = bor_create_socket_in(SOCK_STREAM, 0, &adr_client);
    if(soc < 0)
        return 1;
		
	struct sockaddr_un adr_serveur;
	if(bor_resolve_address_in(nom_serveur, atoi( argv[2] ), &adr_serveur) < 0){goto fin1;}
	if(bor_connect_in(soc, &adr_serveur) < 0){goto fin1;}

    int pos = 0;
    while( 1 )
    {
        k = bor_read_str( soc, buf+pos, sizeof( buf ) - pos );
        if( k <= 0 ) break;
        defragmenter_ligne( buf, sizeof( buf ), &pos );
    }
	
	fin1:
		close(soc);
		exit(k < 0 ? 1 : 0);
}




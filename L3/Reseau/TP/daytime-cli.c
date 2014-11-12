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

int main(int argc, char* argv[])
{
    (void) argc;
    (void) argv;

    if(argc - 1 != 1)
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
	if(bor_resolve_address_in(nom_serveur, 13, &adr_serveur) < 0){goto fin1;}
	if(bor_connect_in(soc, &adr_serveur) < 0){goto fin1;}

    int k;

    while( 1 )
    {
        k = dialoguer_avec_serveur( soc );
        if( k == 0) break;
    }
	
	fin1:
		close(soc);
		exit(k < 0 ? 1 : 0);
}

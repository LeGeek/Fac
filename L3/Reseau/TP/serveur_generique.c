// TD8
// EX1
#define SLOTS_NB 32
#include <stdio.h>
#include <stdlib.h>
#include "bor-util.h"

typedef enum {E_LIBRE, E_LIRE_REQUETE, E_ECRIRE_REPONSE}Etat;

typedef struct{
	Etat etat;
	int soc; /* Socket de service, défaut -1 */
	struct sockaddr_in adr; /* adresse du client */
} Slot;

void init_slot(Slot *o)
{
    memset(&o->adr, 0,sizeof o->adr);
    o->soc = -1;
    o->etat = E_LIBRE;
}

int slot_est_libre(Slot *o)
{
	return o->etat == E_LIBRE;
}

void liberer_slot(Slot *o)
{
	if(slot_est_libre(o))
        return;
    o->etat = E_LIBRE;
    close(o->soc);
    init_slot(o);
}

// EX2

typedef struct{
    Slot slots[SLOTS_NB];
    int soc_ec; // Socket d'écoute 
    struct sockaddr_in adr; // Adresse du serveur 
}Serveur;

void init_serveur(Serveur *ser)
{
    int i;
    for(i = 0; i < SLOTS_NB; ++i)
    {
        init_slot(&ser->slots[i]);
    }
    ser->soc_ec = -1;
}

int chercher_slot_libre(Serveur *ser)
{
    int i;
    for(i = 0; i < SLOTS_NB; ++i)
    {
        if(slot_est_libre(&ser->slots[i]))
            return i;
    }
    return -1;
}

// EX3

int demarrer_serveur(Serveur *ser, int port)
{
    init_serveur(ser);
    ser->soc_ec = bor_create_socket_in(SOCK_STREAM, port, &ser->adr);
    if(ser->soc_ec < 0)
        return -1;
    if(bor_listen(ser->soc_ec,8) < 0)
    {
        close(ser->soc_ec);
        ser->soc_ec =-1;
        return -1;
    }
    return 0;
}

void fermer_serveur(Serveur *ser)
{
    int i;
    close(ser->soc_ec);
    for(i = 0; i < SLOTS_NB; ++i)
    {
        liberer_slot(&ser->slots[i]);
    }
}

// EX4

int accepter_connexion(Serveur *ser)
{
    struct sockaddr_in adr_client;
    printf("Serveur : connexion en cours .. \n");
    int soc_se = bor_accept_in(ser->soc_ec, &adr_client);
    if(soc_se < 0) return -1;
    int i = chercher_slot_libre(ser);
    if(i < 0){
        close(soc_se);
        printf("Serveur : connexion refusé avec %s : trop de client \n", bor_adrtoa_in(&adr_client));
        return 0;
    }
    printf("Serveur [%d] : connexion établie avec %s \n", i, bor_adrtoa_in(&adr_client));
    Slot *o = &ser->slots[i];
    o->soc = soc_se;
    o->adr = adr_client;
    o->etat = E_LIRE_REQUETE;
    return 1;
}

// EX5

int proceder_lecture_requete(Slot *o)
{

}

int proceder_ecriture_requete(Slot *o)
{

}

void traiter_slot_si_eligible(Slot *o, fd_set *set_read, fd_set *set_write)
{
    int k = 1;
    if(slot_est_libre(o))return;
    switch (o->etat) {
        case E_LIRE_REQUETE :
            if(FD_ISSET(o->soc, set_read))
                k = proceder_lecture_requete(o);
            break;
        case E_ECRIRE_REPONSE :
            if(FD_ISSET(o->soc, set_write))
                proceder_ecriture_requete(o);
            break;
        default : ;
	}
    if(k <= 0)
    {
        printf("Serveur [%d]: libération du slot \n", o->soc);
        liberer_slot(o);
    }
}

void inserer_fd(int fd, fd_set *set, int *maxfd)
{
    FD_SET(fd,set);
    if(*maxfd < fd) *maxfd = fd;
}

void preparer_select(Serveur *ser, int *maxfd, fd_set *set_read, fd_set *set_write)
{
    FD_ZERO(set_read);
    FD_ZERO(set_write);
    *maxfd = -1;

    inserer_fd(ser->soc_ec,set_read, maxfd);
    for(int i = 0; i < SLOTS_NB; i++) {
		Slot *o = &ser->slots[i];
		if(slot_est_libre(o)) continue;
		switch(o->etat) {
		case E_LIRE_REQUETE :
			inserer_fd(o->soc, set_read, maxfd);
			break;
		case E_ECRIRE_REPONSE :
			inser_fd(o->soc, set_write, maxfd);
			break;
		default : ;
		}
	}
}

// TP8
// EX1

int faire_scrutation(Serveur *ser)
{
	
}




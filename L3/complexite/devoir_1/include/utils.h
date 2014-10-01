#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/**
 * \file utils.c
 * \brief Le fichier utils fournit quelque outils utilent afin de faciliter le développement
 **/

/**
 * \brief Permet de savoir si la Seed de rand a été paramétrée
 **/
bool utils_seedChange = false;

/**
 * \brief Génére un tableau à la taille voulu
 * \fn int * genererTableau( int size, bool init )
 * \param taille La taille du tableau généré
 * \param init Indique si les valeur du tableau doivent être initialisées à la valeur par défaut (ex. 0, NULL, ...)
 * \return le tableau généré initialisé
 */
int * genererTableau( int size, bool init )
{
    if( init )
        return (int*)malloc(size * sizeof( int ) );
    else
        return (int*)calloc(size, sizeof( int ) );
}

/**
 * \brief Génère un nombre aléatoire
 * \fn int random( int min, int max )
 * \param min Borne minimale
 * \param max Borne maximale
 * \return Un nombre compris dans l'intervalle min, max
 **/
int random( int min, int max )
{
    if( !utils_seedChange )
    {
        srand( time(NULL) );
        utils_seedChange = true;
    }

    return rand()%(max-min) + min;
}

/**
 * \brief Echange deux éléments entre eux
 * \fn void swapi( int * a, int * b )
 * \param a Element qui se retrouvera à la place de b
 * \param b Element qui se retrouvera à la palce de a
 **/
inline void swapi( int * a, int * b);
void swapi( int * a, int * b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

#endif

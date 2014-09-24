#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * \file utils.c
 * \brief Le fichier utils fournit quelque outils utilent afin de faciliter le développement
 **/

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



#endif

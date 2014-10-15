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
static bool utils_seedChange = false;

/**
 * \fn int * genererTableau( int size, bool init )
 * \brief Génére un tableau à la taille voulu
 * \param taille La taille du tableau généré
 * \param init Indique si les valeur du tableau doivent être initialisées à la valeur par défaut (ex. 0, NULL, ...)
 * \return le tableau généré initialisé
 */
int * genererTableau( int size, bool init );

/**
 * \fn int random( int min, int max )
 * \brief Génère un nombre aléatoire
 * \param min Borne minimale
 * \param max Borne maximale
 * \return Un nombre compris dans l'intervalle min, max
 **/
int random( int min, int max );

/**
 * \fn void swapi( int * a, int * b )
 * \brief Echange deux éléments entre eux
 * \param a Element qui se retrouvera à la place de b
 * \param b Element qui se retrouvera à la palce de a
 **/
void swapi( int * a, int * b);

/**
 * \fn decalerTableau( int * tab, int debut, int fin )
 * \brief Décale le contenue d'un tableau à partir d'un indice de début,
 * jusqu'a l'indice de fin
 * \param[in, out] tab Le tableau sur lequel effectuer le décalage
 * \param[in] debut L'indice de début du décalage
 * \param[in] fin L'indice de fin du décalage
 **/
void decalerTableau( int * tab, int debut, int fin );

#endif

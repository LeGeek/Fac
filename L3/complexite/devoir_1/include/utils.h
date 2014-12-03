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
 * \fn int * genererTableau( int taille, bool init )
 * \brief Génére un tableau à la taille voulu
 * \param[in] taille La taille du tableau généré
 * \param[in] init Indique si les valeur du tableau doivent être initialisées à la valeur par défaut (ex. 0, NULL, ...)
 * \return le tableau généré initialisé
 */
int * genererTableau( int taille, bool init );

/**
 * \fn int randomMinMax( int min, int max )
 * \brief Génère un nombre aléatoire
 * \param[in] min Borne minimale
 * \param[in] max Borne maximale
 * \return Un nombre compris dans l'intervalle min, max
 **/
int randomMinMax( int min, int max );

/**
 * \fn void swapi( int * a, int * b )
 * \brief Echange deux éléments entre eux
 * \param[in, out] a Element qui se retrouvera à la place de b
 * \param[in, out] b Element qui se retrouvera à la palce de a
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


/**
 * \brief Cherche l'élément le plus petit dans le tableau à partir d'une
 * position de départ
 * jusqu'à une position de fin.
 * \fn int chercherPetit( const int * tab, int debut, int fin )
 * \param[in] tab Le tableau dans lequel il faut rechercher
 * \param[in] debut La position de départ
 * \param[in] fin La position de fin
 * \return L'indice de la plus petite valeur
 **/
int chercherPetit( const int * tab, int debut, int fin );


#endif

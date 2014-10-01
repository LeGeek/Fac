#ifndef __INSERTSEQ_H__
#define __INSERTSEG_H__

/**
 * \brief Tri le tableau avec l'algorithme de l'insertion séquentielle
 * \fn void insertionSequentielle( int * tab, int taille )
 * \param tab Le tableau à trier
 * \param taille La taille du tableau
 **/
void insertionSequentielle( int * tab, int taille );

/**
 * \brief Cherche l'élément le plus petit dans le tableau à partir d'une position de départ
 * jusqu'à une position de fin.
 * \fn int cherchePetit( const int * tab, int debut, int fin )
 * \param tab Le tableau dans lequel il faut rechercher
 * \param debut La position de départ
 * \param fin La position de fin
 * \return L'indice de la plus petite valeur
 **/
int cherchePetit( const int * tab, int debut, int fin );

/**
 * \brief Décale une partie d'un tableau
 * \fn void decaler( int * tab, int debut, int fin )
 * \param tab Le tableau dans lequel le décalage doit s'effectuer
 * \param debut L'indice de début du décalage
 * \param fin L'indice de fin du décalage
 **/
void decaler( int * tab, int debut, int fin );

#endif

#ifndef __INSERTSEQ_H__
#define __INSERTSEG_H__

/**
 * \brief Tri le tableau avec l'algorithme de l'insertion séquentielle
 * \fn void IS_insertionSequentielle( int * tab, int taille )
 * \param[in, out] tab Le tableau à trier
 * \param[in] taille La taille du tableau
 **/
void IS_insertionSequentielle( int * tab, int taille );

/**
 * \brief Cherche l'élément le plus petit dans le tableau à partir d'une position de départ
 * jusqu'à une position de fin.
 * \fn int IS_cherchePetit( const int * tab, int debut, int fin )
 * \param[in] tab Le tableau dans lequel il faut rechercher
 * \param[in] debut La position de départ
 * \param[in] fin La position de fin
 * \return L'indice de la plus petite valeur
 **/
int IS_cherchePetit( const int * tab, int debut, int fin );

#endif

#ifndef __QUICK_H__
#define __QUICK_H__

/**
 * \brief Trie le tableau avec l'algorithme du tri rapide
 * \fn QS_quickSort( int * tab, int taille );
 * \param[in, out] tab Le tableau a trier
 * \param[in] taille La taille du tableau
 **/
void QS_quickSort( int * tab, int taille );

/**
 * \brief Effectue le tri du tableau
 * \fn QS_sort( int * tab, int debut, int fin )
 * \param[in, out] tab Le tableau à trier
 * \param[in] debut Le début du tableau
 * \param[in] fin La fin du tableau
 **/
void QS_sort( int * tab, int debut, int fin );

/**
 * \brief Determine la position du piveau
 * \fn int QS_placerPivot( int * tab, int debut, int fin )
 * \param[in, out] tab Le tableau ou pivot doit se placer
 * \param[in] debut Le début du tableau
 * \param[in] fin La fin du tableau
 * \return Un entier représentant l'indice du pivot
 **/
int QS_placerPivot( int * tab, int debut, int fin );


#endif

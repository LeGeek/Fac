#ifndef __FUSION_H__
#define __FUSION_H__

/**
 * \brief Tri le tableau avec l'algorithme de tri par fusion
 * \fn void void FU_fusion( int * tab, int taille )
 * \param[in, out] tab Le tableau à trier
 * \param[in] taille La taille du tableau
 **/
 void FU_fusion( int * tab, int taille );

/**
 * \brief Trie le tableau sur un interval
 * \fn void FU_trierTableau( int * tab, int debut, int fin )
 * \param[in, out] tab Le tableau à trier
 * \param[in] debut debut de l'interval
 * \param[in] fin fin de l'interval
 **/
void FU_trierTableau( int * tab, int debut, int fin);

/**
 * \brief Fusionne deux tableaux
 * \fn void FU_fusionTableau( int * tab, int debut, int fin )
 * \param[in, out] tab Le tableau à fusionner
 * \param[in] debut Debut de l'interval
 * \param[in] fin Fin de l'interval
 **/
void FU_fusionTableau( int * tab, int debut, int fin );

#endif

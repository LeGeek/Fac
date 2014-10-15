#ifndef __INSERTDICHO_H__
#define __INSERTDICHO_H__

/**
 * \fn ID_insertionDichotomique( int * tab, int taille )
 * \brief Tri le tableau avec l'algorithme d'insertion dichotomique
 * \param[in, out] tab Le tableau à trier
 * \param[in] taille La taille du tableau à trier
 **/
void ID_insertionDichotomique( int * tab, int taille );

/**
 * \fn int ID_chercherPetit( const int * tab, int debut, int fin )
 * \brief Cherche l'élément le plus petit, de manière dichotomique
 * \param[in] tab Le tableau dans lequel rechercher
 * \param[in] debut L'indice de début de recherche
 * \param[in] fin L'indice de fin de recherche
 * \return L'indice de l'élément le plus petit
 **/
int ID_chercherPetit( const int * tab, int debut, int fin );



#endif

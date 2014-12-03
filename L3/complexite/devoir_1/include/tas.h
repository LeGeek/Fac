#ifndef __TAS_H__
#define __TAS_H__

/**
 * \brief Tri un tableau en utilisant le tri par tas
 * \fn TS_triParTas( int * tab, int taille )
 * \param[in, out] tab Le tableau à trier
 * \param[in] taille La taille du tableau
 **/
void TS_triParTas( int * tab, int taille );

/**
 * \brief Transfome un tableau en Tas max
 * \fn void TS_formerTas( int * tab, int taille )
 * \param[in, out] tab Le tableau à transformer
 * \param[in] taille La taille du tableau
 **/
void TS_formerTas( int * tab, int taille );

#endif

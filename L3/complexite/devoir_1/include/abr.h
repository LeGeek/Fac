#ifndef __ABR_H__
#define __ABR_H__


typedef struct TreeAbr TreeAbr;
struct TreeAbr
{
    int value;
    TreeAbr * left;
    TreeAbr * right;
};

/**
 * \brief Tir un tableau en utilisant un arbre binaire de recherche
 * \fn AR_arbreBinaire( int * tab, int taille )
 * \param[in, out] tab Le tableau à trier
 * \param[in] taille La taille du tableau
 **/
void AR_arbreBinaire( int * tab, int taille );

/**
 * \brief Ajoute un élément dans l'arbre, en le placant au bon endroit
 * \fn AR_placerElement( TreeAbr * head, int element )
 * \param[in, out] head Arbre dans lequel on essai de placer l'élément
 * \param[in] element L'élément à placer
 **/
void AR_placerElement( TreeAbr * head, int element );


/**
 * \brief Applique l'arbre binaire dans un tableau
 * \fn AR_rangerTableau( int * tab, int * pos, const TreeAbr * head )
 * \param[in, out] tab Le tableau dans lequel ranger les valeurs de l'arbre
 * \param[in] pos Position de l'élément dans le tableau
 * \param[in] head La noeud à partir d'où commencer le remplissage
 **/
void AR_rangerTableau( int * tab, int * pos, const TreeAbr * head );

/**
 * \brief Détruit l'arbre binaire
 * \fn AR_detruireArbre( TreeAbr * head )
 * \param[in, out] head Noeud à partir d'où la destruction commence
 **/
void AR_detruireArbre( TreeAbr * head );


/**
 * \brief Initialise une structure de type TreeAbr
 * \fn AR_initTreeAbr( TreeAbr * s, int value )
 * \param[in, out] s La structure à initialiser
 * \param[in] value La valeur à appliquer
 **/
void AR_initTreeAbr( TreeAbr * s, int value );

#endif

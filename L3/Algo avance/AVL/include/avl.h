#ifndef __AVL_H__
#define __AVL_H__

#include <vector>
#include <fstream>

/**
 * \class AVL __AVL_H__ avl.h
 * \brief Structure minimal d'un arbre AVL
 **/
template< typename T > 
class AVL
{
    public:
        /**
         * \fn AVL( T value, AVL parent, AVL left, AVL right )
         * \brief Créé une structure d'arbre AVL avec une valeur et une branche gauche
         * \param value Valeur attribuée à la structure
         * \param parent Arbre parent du nouvel arbre
         * \param left Arbre enfant positionné à gauche
         * \param right Arbre enfant positionné à droite
         **/
        AVL( T value, AVL * parent = NULL, AVL * left = NULL, AVL * right = NULL);

        /**
         * \fn ~AVL()
         * \brief Destructeur de la classe
         **/
        virtual ~AVL();

        /**
         * \fn int getLevel()
         * \brief Accesseur à la donnée membre level
         * \return Un entier représentant la hauteur de l'arbre
         **/
        int getLevel();

        /**
         * \fn int getLeftLevel()
         * \brief Retourne le niveau du fils gauche
         * \return Un entier valant 0 si le fils gauche vaut NULL
         **/
        int getLeftLevel();

        /**
         * \fn int getRightLevel()
         * \brief Retourne le niveau du fils droit
         * \return Un entier valalnt 0 si le fils droit vaut NULL
         **/
        int getRightLevel();

        /**
         * \fn bool contains( T val )
         * \brief Recherche la présence d'un élément dans l'arbre
         * \param val Valeur à rechercher
         * \return TRUE si l'élément est dans l'arbre, FALSE dans le cas
         * contraire
         **/
        bool contains( T val );

        /**
         * \fn void insert( T val )
         * \brief Ajoute un élément dans l'arbre
         * \param val Valeur à ajouter
         **/
        void insert( T val );

        /**
         * \fn void updateLevel()
         * \brief Calcule le niveau du noeud
         **/
        void updateLevel();

        /**
         * \fn void balance()
         * \brief Equilibre l'arbre si besoin
         **/
        void balance();

        /**
         * \fn void drawGraph()
         * \brief Edit l'arbre au format DOT, sur un flux
         * \param fs Flux sur lequel sera edité l'arbre
         **/
        void drawGraph( std::ostream & fs);
        
        /**
         * \fn void rotateRight()
         * \brief Effectue une rotation vers la droite
         **/
        void rotateRight();

        /**
         * \fn void rotateLeft()
         * \brief Effectue une rotation vers la gauche
         **/
        void rotateLeft();
        
        T value;           ///< Valeur de la noeud
        AVL * left;    ///< Arbre enfant positionné à droite
        AVL * right;   ///< Arbre enfant positionné à gauche
        AVL * parent;  ///< Noeud parent

    private:
        int level;  ///< Hauteur du noeud

};

#include "avl.hpp"

#endif

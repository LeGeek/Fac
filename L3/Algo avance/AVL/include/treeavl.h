#ifndef __TREEAVL_H__
#define __TREEAVL_H__

#include "avl.h"
#include <fstream>


/**
 * \class TreeAVL __TREEAVVL_H__ treeavl.h
 * \brief Classe permettant de simplifier l'utilisation des arbres AVL
 **/
template< typename T >
class TreeAVL
{
    public:
        /**
         * \fn TreeAVL()
         * \brief Créé un support pour un arbre AVL
         **/
        TreeAVL();
        
        /**
         * \fn void insert( T value )
         * \brief Ajoute un élément dans l'arbre à partir de la racine
         * \param value Valeur à ajouter 
         **/
        void insert( T value );
        
        /**
         * \fn bool contains( T val );
         * \brief Cherche dans tout l'arbre si l'élément val existe
         * \param val Valeur à chercher
         * \return TRUE si l'élément est dans l'arbre, FALSE dans le cas
         * contraire
         **/
        bool contains( T val );

        /**
         * \fn void drawGraph( std::ostream & fs )
         * \brief Edite l'arbre AVL au format DOT, à partir de la racine
         * \param fs Flux dans lequel écrire
         **/
        void drawGraph( std::ostream & fs );

        /**
         * \fn void drawGraph( const char * file )
         * \brief Edite l'arbre dans un fichier, au format DOT, à partir de la
         * racine
         * \param file Nom du fichier à créer, si le fichier existe il sera
         * effacé
         **/
        void drawGraph( const char * file );

        /**
         * \fn void clear()
         * \brief Efface la racine de l'arbre, qui a pour concequence de
         * supprimer la totalité de l'arbre;
         **/
        void clear();

    private:
        /**
         * \fn void relocateHead()
         * \brief Replace la tête à la racine de l'arbre
         **/
        void relocateHead();

        AVL<T> * head; ///< Tête pointant sur la racine de l'arbre
};

#include "treeavl.hpp"

#endif

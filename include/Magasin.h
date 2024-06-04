#ifndef _MAGASIN
#define _MAGASIN

#include "Article.h"

/**
@brief classe Magasin
**/

class Magasin
{
private:
	unsigned int nbCostumes; //!< defini le nombre de costumes
	unsigned int nbDecors; //!< defini le nombre de décors
	
/**
@brief chargerCostumes: remplit costumes à partir d'un fichier texte 
@param none
**/
	void chargerCostumes();
	
/**
@brief chargerDecors: remplit decors à partir d'un fichier texte 
@param none
**/
	void chargerDecors();
	
public:
	Article * costumes; //!< defini le tableau de costumes
	Article * decors; //!< defini le tableau de décors
	unsigned int pieces; //!< defini le nombre de pièces

/**
@brief constructeur de Magasin
@param none
**/
	Magasin();

/**
@brief destructeur de Magasin
@param none
**/	
	~Magasin();
	
/**
@brief acheterArticle: achète l'article pointé
@param none
**/
	void acheterArticle(Article & article);
	
/**
@brief accesseur de nbCostumes
@param none
@return unsigned int le nombre de costumes 
**/
	unsigned int getNbCostumes()const;
	
/**
@brief accesseur de nbDecors 
@param none
@return unsigned int le nombre de décors
**/
	unsigned int getNbDecors()const;

/**
@brief testRegression : teste le bon fonctionnement de la classe
@param none
**/
	void testRegression()const;

};

#endif

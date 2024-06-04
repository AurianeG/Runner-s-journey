#ifndef _OBJET
#define _OBJET

#include "Position.h"

/**
@brief classe Objet
**/

class Objet
{
private:
	unsigned int type; //!< definit le type de l'objet (bonus, piece, obstacle)
	unsigned int typeSecondaire; //!< definit le sous type de l'objet (bonus d'invincibilité, arbre, rocher)
	
public:
	Position position; //!< definit la position de l'objet

/**
@brief constructeur de Objet
@param none
**/
	Objet();

/**
@brief destructeur de Objet
@param none
**/
	~Objet();
	
/**
@brief mutateur de type
@param unsigned int t correspond à la valeur de type
**/
	void setType (const unsigned int t);
	
/**
@brief accesseur de type
@param none
@return unsigned int le type de l'objet
**/
	unsigned int getType()const;

/**
@brief mutateur de typeSecondaire
@param unsigned int t correspond à la valeur de typeSecondaire
**/
	void setTypeSecondaire (const unsigned int t);
	
/**
@brief accesseur de typeSecondaire
@param none
@return unsigned int le typeSecondaire de l'objet
**/
	unsigned int getTypeSecondaire()const;


	
};

#endif

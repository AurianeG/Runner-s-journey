#ifndef _PERSONNAGE
#define _PERSONNAGE

#include "Position.h"

/**
@brief classe Personnage
**/

class Personnage
{
private:
	unsigned int costume; //!< definit le costume du personnage
	unsigned int animation; //!< definit l'image correspondante à l'animation du personnage
	unsigned int bonus; //!< definit le type du dernier bonus rammassé par le personnage
	float finBonus; //!< definit la seconde à laquelle le bonus prend fin
	
public:
	Position position;
		
/**
@brief constructeur de Personnage
@param none
**/
	Personnage();

/**
@brief destructeur de Personnage
@param none
**/
	~Personnage();

/**
@brief initialisation: initialise le personnage
@param int px la position horizontale
@param int py la position verticale
**/
	void initialisation(const int px, const int py);

/**
@brief mutateur de costume
@param unsigned int cost qui contient le numéro du costume du personnage
**/
	void setCostume (const unsigned int cost);
	
/**
@brief accesseur de costume
@param none
@return unsigned int le numéro du costume
**/
	unsigned int getCostume()const;
	
/**
@brief mutateur de animation
@param unsigned int anim qui contient le numéro d'animation du personnage
**/
	void setAnimation (const unsigned int anim);
	
/**
@brief accesseur de animation
@param none
@return unsigned int le numéro d'animation
**/
	unsigned int getAnimation()const;
	
/**
@brief mutateur de bonus
@param unsigned int bon qui contient le type du bonus ramassé
**/
	void setBonus (const unsigned int bon);
	
/**
@brief accesseur de bonus
@param none
@return unsigned int le type du dernier bonus ramassé
**/
	unsigned int getBonus()const;
	
/**
@brief mutateur de finBonus
@param float finBon qui contient la seconde à laquelle le bonus prend fin
**/
	void setFinBonus (const float finBon);
	
/**
@brief accesseur de bonus
@param none
@return float la seconde à laquelle le bonus prend fin
**/
	float getFinBonus()const;
	
};

#endif

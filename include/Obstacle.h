#ifndef _OBSTACLE
#define _OBSTACLE

/**
@brief classe Obstacle
**/

class Obstacle
{
private:
	unsigned int largeur; //!< definit la largeur de l'obstacle
	unsigned int hauteur; //!< definit la hauteur de l'obstacle
	
public:
/**
@brief setHauteur : mutateur de hauteur
@param unsigned int haut correspond à la valeur de hauteur
**/
	void setHauteur (const unsigned int haut);
	
/**
@brief getHauteur : accesseur de hauteur
@param none
@return unsigned int la hauteur de l'objet
**/
	unsigned int getHauteur ()const;
	
/**
@brief setLargeur : mutateur de largeur
@param unsigned int larg correspond à la valeur de largeur
**/
	void setLargeur (const unsigned int larg);
	
/**
@brief getLargeur : accesseur de largeur
@param none
@return unsigned int la largeur de l'objet
**/
	unsigned int getLargeur ()const;
	
};

#endif

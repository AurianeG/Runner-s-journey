#ifndef _POSITION
#define _POSITION

/**
@brief classe Position
**/

class Position
{
private : 
	unsigned int hauteur; //!< definit la hauteur de l'objet
	unsigned int largeur; //!< definit la largeur de l'objet

public : 
	int x; //!< definit la position horizontale de l'objet
	int y; //!< definit la position verticale de l'objet
    
/**
@brief constructeur de Position
@param none
**/
	Position();

/**
@brief constructeur de Position
@param int px la position horizontale
@param int py la position verticale
@param int h la hauteur
@param int l la largeur
**/
	Position(const int px, const int py, const unsigned int h, const unsigned int l);
    
/**
@brief destructeur de Position
@param none
**/
	~Position();

/**
@brief deplacer: modifie la position de l'instance
@param int deplX correspond au déplacement horizontal de l'instance
@param int deplY correspond au déplacement vertical de l'instance
**/
	void deplacer(const int deplX, const int deplY);


/**
@brief mutateur de hauteur
@param int h qui contient la hauteur de l'instance
**/
	void setHauteur(const unsigned int h);
       
/**
@brief accesseur de hauteur
@param none
@return unsigned int la hauteur de l'instance
**/
	unsigned int getHauteur()const;

/**
@brief mutateur de largeur
@param int l qui contient la largeur de l'instance
**/
	void setLargeur(const unsigned int l);
    
    
/**
@brief accesseur de largeur
@param none
@return unsigned int la largeur de l'instance
**/
	unsigned int getLargeur()const;

};


#endif

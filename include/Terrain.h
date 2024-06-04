#ifndef _TERRAIN
#define _TERRAIN

/**
@brief classe Terrain
**/

class Terrain
{	
private:
	unsigned int dimx; //!< definit la largeur du tableau 2D parcours
	unsigned int dimy; //!< definit la hauteur du tableau 2D parcours
	unsigned int hauteur; //!< definit la hauteur du terrain dans laquel le personnage peut se deplacer
	unsigned int largeur; //!< definit la largeur du terrain dans lequel le personnage peut se deplacer et qui sera afficher
	unsigned int decor; //!< definit le numéro du décor

public:	

/**
@brief constructeur de Terrain
@param none
**/
	Terrain();

/**
@brief constructeur de Terrain
@param unsigned int dx la dimension horizontale du tableau
@param unsigned int dy la dimension verticale du tableau
@param unsigned int h la hauteur du terrain
@param unsigned int l la largeur du terrain
**/
	Terrain(const unsigned int dx, const unsigned int dy, const unsigned int h, const unsigned int l);

/**
@brief destructeur de Terrain
@param none
**/
	~Terrain();

/**
@brief mutateur de decor
@param unsigned int dec correspond au numéro du décor
**/
	void setDecor (const unsigned int dec);

/**
@brief accesseur de decor
@param none
@return unsigned int le numéro du décor
**/
	
	unsigned int getDecor()const;


/**
@brief accesseur de dimx
@param none
@return unsigned int la taille verticale de parcours
**/
	unsigned int getDimx()const;


/**
@brief accesseur de dimy
@param none
@return unsigned int la taille horizontale de parcours
**/
	unsigned int getDimy()const;


/**
@brief accesseur de hauteur
@param none
@return unsigned int la hauteur du terrain
**/
	unsigned int getHauteur()const;


/**
@brief accesseur de largeur
@param none
@return unsigned int la largeur du terrain
**/
	unsigned int getLargeur()const;

/**
@brief test la classe Terrain
@param none
**/
	void testRegression()const;

	
};

#endif

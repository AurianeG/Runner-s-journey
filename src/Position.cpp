#include "../include/Position.h"
Position :: Position()  {
    x = 0;
    y = 0;
    hauteur = 0;
    largeur = 0;
}

Position :: Position(const int px, const int py, const unsigned int h, const unsigned int l)
{
	x = px;
    	y = py;
    	hauteur = h;
    	largeur = l;
}

    
Position :: ~Position ()  {
    x = 0;
    y = 0;
    hauteur = 0;
    largeur = 0;
}

void Position :: deplacer(const int deplX,const int deplY)   {
	x = x + deplX;
	y = y + deplY;
}

void Position :: setHauteur(const unsigned int h)	{
	hauteur = h;
}

unsigned int Position :: getHauteur()const	{
	return hauteur;
}

void Position :: setLargeur(const unsigned int h)	{
	largeur = h;
}

unsigned int Position :: getLargeur()const	{
	return largeur;
}

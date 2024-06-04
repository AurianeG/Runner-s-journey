#include "../include/Obstacle.h"

void Obstacle :: setHauteur (const unsigned int haut)
{
	hauteur=haut;
}

unsigned int Obstacle :: getHauteur ()const
{
	return hauteur;
}

void Obstacle :: setLargeur (const unsigned int larg)
{
	largeur=larg;
}

unsigned int Obstacle :: getLargeur ()const
{
	return largeur;
}

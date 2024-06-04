#include "../include/Personnage.h"

Personnage ::Personnage()
{
	costume =0;
	animation =0;
	bonus=0;
	finBonus=0;
	position.setHauteur(8);
	position.setLargeur(8);
}
	
Personnage ::~Personnage()
{
	costume =0;
	animation =0;
	bonus=0;
	finBonus=0;
}	
	
void Personnage :: initialisation (const int px, const int py)
{
	position.x=px;
	position.y=py;
	bonus=0;
	finBonus=0;
	animation=0;
}

void Personnage ::setCostume (const unsigned int cost)	{
	costume = cost;
}

unsigned int Personnage :: getCostume()const	{
	return costume;
}

void Personnage ::setAnimation (const unsigned int anim)	{
	animation = anim;
}

unsigned int Personnage :: getAnimation()const	{
	return animation;
}

void Personnage ::setBonus (const unsigned int bon)	{
	bonus = bon;
}

unsigned int Personnage :: getBonus()const	{
	return bonus;
}

void Personnage ::setFinBonus (const float finBon)	{
	finBonus = finBon;
}

float Personnage :: getFinBonus()const	{
	return finBonus;
}


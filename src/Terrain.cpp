#include "../include/Terrain.h"
#include <iostream>
#include <cassert>

Terrain::Terrain()	{
	
	
	dimx = 180;
	dimy = 121;
	hauteur = 87;
	largeur = 160;
	decor= 0;
}

Terrain::Terrain(const unsigned int dx, const unsigned int dy, const unsigned int h, const unsigned int l)	{
	dimx = dx;
	dimy = dy;
	hauteur = h;
	largeur = l;
	decor= 0;
}
	
Terrain::~Terrain(){
	hauteur=0;
	largeur=0;
	dimx=0;
	dimy=0;
}

void Terrain::setDecor (const unsigned int dec)	{
	decor = dec;
}
	
unsigned int Terrain::getDecor()const	{
	return decor;
}

	
unsigned int Terrain::getDimx()const	{
	return dimx;
}
	
unsigned int Terrain::getDimy()const	{
	return dimy;
}
	
unsigned int Terrain::getHauteur()const	{
	return hauteur;
}
	
unsigned int Terrain::getLargeur()const	{
	return largeur;
}

void Terrain::testRegression()const{
	std::cout<<"Terrain:";
	Terrain test(800,500,300,500);
	assert (test.getDimx()==800 && test.getDimy()==500 && test.getHauteur()==300 && test.getLargeur()==500 && test.decor==0);
	std::cout<<" OK"<<std::endl;
}


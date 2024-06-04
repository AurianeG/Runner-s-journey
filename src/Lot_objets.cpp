#include "../include/Lot_objets.h"
#include <fstream>
#include <cassert>
#include <iostream>
using namespace std;

const unsigned int HAUTEUR_PIECE=4;
const unsigned int LARGEUR_PIECE=4;
const unsigned int HAUTEUR_BONUS=6;
const unsigned int LARGEUR_BONUS=6;

Lot_objets :: Lot_objets()
{
	nbObjets=0;
	capacite=20;
	obstacles=NULL;
	dureeBonus=NULL;
	objets=new Objet [capacite];
	chargerObstacles();
	chargerDureeBonus();
}

Lot_objets :: ~Lot_objets()
{
	if (objets!=NULL)
		delete [] objets;
	if (obstacles!=NULL)
		delete [] obstacles;
	if (dureeBonus!=NULL)
		delete [] dureeBonus;
	nbObjets=0;
	capacite=0;
	nbObstacles=0;
	nbBonus=0;
	objets=NULL;
	obstacles=NULL;
	dureeBonus=NULL;
}

void Lot_objets :: chargerObstacles()
{
	ifstream fichier("./data/textes/données/obstacles.txt");
	assert(fichier.is_open());
	string mot;
	fichier>>mot;
	fichier>>nbObstacles;
	if (obstacles!=NULL)
		delete [] obstacles;
	obstacles=new Obstacle [nbObstacles];
	unsigned int dim;
	for (unsigned int i=0;i<nbObstacles;i++)
	{
		fichier>>mot>>mot>>dim;
		obstacles[i].setHauteur(dim);
		fichier>>mot>>dim;
		obstacles[i].setLargeur(dim);
	}
	fichier.close();
}

void Lot_objets :: chargerDureeBonus()
{
	ifstream fichier ("./data/textes/données/duréeBonus.txt");
	assert(fichier.is_open());
	string mot;
	fichier>>mot;
	fichier>>nbBonus;
	if (dureeBonus!=NULL)
		delete [] dureeBonus;
	dureeBonus=new unsigned int [nbBonus];
	for (unsigned int i=0;i<nbBonus;i++)
	{
		fichier>>mot>>mot>>dureeBonus[i];
	}
	fichier.close();
}

void Lot_objets :: initialisation()
{
	if (objets!=NULL)
		delete [] objets;
	nbObjets=0;
	capacite=20;
	objets=new Objet [capacite];
}

void Lot_objets :: addObjet (const unsigned int tp, const unsigned int tps)
{
	assert(0<tp && tp<=3);	
	if (nbObjets==capacite)
	{
		capacite=capacite+10;
		Objet * nouv=new Objet [capacite];
		for (unsigned int i=0;i<nbObjets;i++)
			nouv[i]=objets[i];
		delete [] objets;
		objets=nouv;
		nouv=NULL;
	}
	objets[nbObjets].setType(tp);
	objets[nbObjets].setTypeSecondaire(tps);
	objets[nbObjets].position.x=0;
	objets[nbObjets].position.y=0;
	switch (tp)
	{
		case 1:{
			assert(tps<nbBonus);
			objets[nbObjets].position.setHauteur(HAUTEUR_BONUS);
			objets[nbObjets].position.setLargeur(LARGEUR_BONUS);
		}break;
		case 2:{
			objets[nbObjets].position.setHauteur(HAUTEUR_PIECE);
			objets[nbObjets].position.setLargeur(LARGEUR_PIECE);
		}break;
		case 3:{
			assert(tps<nbObstacles);
			objets[nbObjets].position.setHauteur(obstacles[tps].getHauteur());
			objets[nbObjets].position.setLargeur(obstacles[tps].getLargeur());
		}break;
		default: break;
	}
	nbObjets++;
}

void Lot_objets :: delObjet (const unsigned int indice)
{
	assert(indice<nbObjets);
	nbObjets--;
	for (unsigned int i=indice;i<nbObjets;i++)
		objets[i]=objets[i+1];
}

unsigned int Lot_objets :: getNbObstacles()const
{
	return nbObstacles;
}

unsigned int Lot_objets :: getNbBonus()const
{
	return nbBonus;
}

unsigned int Lot_objets :: getNbObjets()const
{
	return nbObjets;
}

void Lot_objets :: testRegression()const
{
	cout<<"Initialisation:";
	Lot_objets lot_test;
	assert(lot_test.nbObjets==0 && lot_test.capacite==20);
	cout<<" OK"<<endl<<"addObjets():";
	for (unsigned int i=0;i<25;i++)
		lot_test.addObjet(1+i%3,0);
	assert(25==lot_test.nbObjets);
	for (unsigned int i=0;i<25;i++)
		assert(lot_test.objets[i].getType()==1+i%3);
	cout<<" OK"<<endl<<"delObjets():";
	lot_test.objets[23].setTypeSecondaire(5);
	for (unsigned int i=0;i<10;i++)
		lot_test.delObjet(3);
	assert(15==lot_test.nbObjets && lot_test.objets[13].getTypeSecondaire()==5);
	cout<<" OK"<<endl;
}

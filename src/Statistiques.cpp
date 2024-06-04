#include <iostream>
#include <fstream>
#include <cassert>
#include "../include/Statistiques.h"
using namespace std;


Statistiques::Statistiques()    {
	nbScores = 0;
	capacite =20;
	scoresParties = new Scores[capacite];
 }
	
Statistiques::~Statistiques()   {
    capacite = 0;
    nbScores = 0;
    delete [] scoresParties;
    scoresParties = NULL;
    }

void Statistiques::sauvegarder()const   {
    	ofstream fichier("./data/textes/sauvegardes/statistiques.txt");
	assert(fichier.is_open());
	string mot;
	fichier<<"NB "<<nbScores;
	for (unsigned int i=0; i<nbScores; i++)
		fichier<<endl<<i<<" Score "<<scoresParties[i].score<<" Distance "<<scoresParties[i].distance
			<<" Pièces "<<scoresParties[i].pieces<<" Temps "<<scoresParties[i].temps;
	fichier.close();
}

void Statistiques::charger()    
{
	ifstream fichier("./data/textes/sauvegardes/statistiques.txt");
	assert(fichier.is_open());
	string mot;
	fichier>>mot>>nbScores;
	capacite=nbScores+20;
	if (scoresParties!=NULL)
		delete [] scoresParties;
	scoresParties = new Scores[capacite];
	for (unsigned int i=0; i<capacite; i++)
		fichier>>mot>>mot>>scoresParties[i].score>>mot>>scoresParties[i].distance>>mot
			>>scoresParties[i].pieces>>mot>>scoresParties[i].temps;
	fichier.close();
}
	
void Statistiques::reinitialiser()
{
	if (scoresParties!=NULL)
		delete [] scoresParties;
	nbScores=0;
	capacite=20;
	scoresParties=new Scores [capacite];
	ofstream fichier("./data/textes/sauvegardes/statistiques.txt");
	assert(fichier.is_open());
	fichier<<"NB "<<nbScores;
	fichier.close();
}

	
void Statistiques::addScore(const Scores & score){
	if (nbScores==capacite)
	{
		capacite=capacite+20;
		Scores * nouv=new Scores [capacite];
		for (unsigned int i=0;i<nbScores;i++)
			nouv[i]=scoresParties[i];
		if (scoresParties!=NULL)
			delete [] scoresParties;
		scoresParties=nouv;
	}
	scoresParties[nbScores] =score;
	nbScores++;
}
	
Scores Statistiques::moyenne()const{
	Scores scr;
	if (nbScores!=0)
	{
		scr=total();
		scr.score=scr.score/nbScores;
		scr.distance=scr.distance/nbScores;
		scr.pieces=scr.pieces/nbScores;
		scr.temps=scr.temps/nbScores;
	}
	else
	{
		scr.score=0;
		scr.distance=0;
		scr.pieces=0;
		scr.temps=0;
	}
	return scr;
}

Scores Statistiques::max()const{
	Scores scr;
	scr.initialisation();
	for (unsigned int i=0;i<nbScores;i++)
	{
		if (scr.score<scoresParties[i].score)
			scr.score=scoresParties[i].score;
		if (scr.distance<scoresParties[i].distance)
			scr.distance=scoresParties[i].distance;
		if (scr.pieces<scoresParties[i].pieces)
			scr.pieces=scoresParties[i].pieces;
		if (scr.temps<scoresParties[i].temps)
			scr.temps=scoresParties[i].temps;
	}
	return scr;
}
	
Scores Statistiques::total()const{
	Scores scr;
	scr.initialisation();
	for (unsigned int i=0;i<nbScores;i++)
	{
		scr.score=scr.score+scoresParties[i].score;
		scr.distance=scr.distance+scoresParties[i].distance;
		scr.pieces=scr.pieces+scoresParties[i].pieces;
		scr.temps=scr.temps+scoresParties[i].temps;
	}
	return scr;
}
	
unsigned int Statistiques::getNbScores()const{
    return nbScores;
}

void Statistiques::testRegression()const
{
	Statistiques statTest;
	cout<<"Initialisation:";
	assert(statTest.capacite==20 && statTest.nbScores==0);
	cout<<" OK"<<endl<<"charger():";
	statTest.charger();
	cout<<" OK"<<endl<<"sauvegarder():";
	statTest.sauvegarder();
	cout<<" OK"<<endl<<"initialisation():";
	Scores scr;
	scr.initialisation();
	assert(scr.score==0 && scr.distance==0 && scr.pieces==0 && scr.temps==0);
	cout<<" OK"<<endl<<"addScore():";
	Statistiques statTest2;
	for (unsigned int i=0;i<25;i++)
	{
		scr.score=i;
		statTest2.addScore(scr);
	}
	assert(statTest2.nbScores==25 && statTest2.capacite==40);
	for (unsigned int i=0;i<25;i++)
		assert(statTest2.scoresParties[i].score==i);
	cout<<" OK"<<endl<<"total():";
	scr=statTest2.total();
	assert(scr.score==300);
	cout<<" OK"<<endl<<"max():";
	scr=statTest2.max();
	assert(scr.score==24);
	cout<<" OK"<<endl<<"moyenne():";
	scr=statTest2.moyenne();
	assert(scr.score==12);
	cout<<" OK"<<endl;
}

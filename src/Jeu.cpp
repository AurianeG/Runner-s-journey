#include "../include/Jeu.h"
#include<cassert>
#include<fstream>
#include <iostream>
using namespace std;

Jeu :: Jeu()
{
	menu=0;
	charger();
	statistiques.charger();
}


void Jeu :: sauvegarder()const
{
	ofstream fichier("./data/textes/sauvegardes/jeu.txt");
	assert(fichier.is_open());
	fichier<<"Pièces "<<magasin.pieces<<endl;
	fichier<<"Costume "<<partie.personnage.getCostume()<<endl;
	fichier<<"Décor "<<partie.terrain.getDecor()<<endl;
	fichier<<"NBCostumes "<<magasin.getNbCostumes()<<endl;
	for (unsigned int i=0;i<magasin.getNbCostumes();i++)
		fichier<<magasin.costumes[i].nom<<" "<<magasin.costumes[i].achete<<endl;
	fichier<<"NBDecors "<<magasin.getNbDecors()<<endl;
	for (unsigned int i=0;i<magasin.getNbDecors();i++)
		fichier<<magasin.decors[i].nom<<" "<<magasin.decors[i].achete<<endl;
	fichier.close();
}

void Jeu :: charger()
{
	ifstream fichier("./data/textes/sauvegardes/jeu.txt");
	assert(fichier.is_open());
	string mot;
	unsigned int valeur;
	bool b;
	fichier>>mot>>magasin.pieces;
	fichier>>mot>>valeur;
	partie.personnage.setCostume(valeur);
	fichier>>mot>>valeur;
	partie.terrain.setDecor(valeur);
	fichier>>mot>>valeur;
	assert(valeur<=magasin.getNbCostumes());
	for (unsigned int i=0; i<valeur; i++)
	{
		fichier>>mot>>b;
		magasin.costumes[i].achete=b;
	}
	fichier>>mot>>valeur;
	assert(valeur<=magasin.getNbDecors());
	for (unsigned int i=0; i<valeur; i++)
	{
		fichier>>mot>>b;
		magasin.decors[i].achete=b;
	}
	fichier.close();
}

void Jeu :: reinitialiser()
{
	partie.personnage.setCostume(0);
	partie.terrain.setDecor(0);
	magasin.pieces=0;
	for (unsigned int i=0;i<magasin.getNbCostumes();i++){
		magasin.costumes[i].achete=0;
	}
	magasin.costumes[0].achete=1;
	for (unsigned int i=0;i<magasin.getNbDecors();i++)
		magasin.decors[i].achete=0;
	magasin.decors[0].achete=1;
	statistiques.reinitialiser();
	menu=0;
}

void Jeu :: equiperCostume(const unsigned int costume)
{
	assert(costume<magasin.getNbCostumes() && magasin.costumes[costume].achete==1);
	partie.personnage.setCostume(costume);
}

void Jeu :: equiperDecor(const unsigned int decor)
{
	assert(decor<magasin.getNbDecors() && magasin.decors[decor].achete==1);
	partie.terrain.setDecor(decor);
}

void Jeu :: finPartie()
{
	magasin.pieces=magasin.pieces+partie.scores.pieces;
	statistiques.addScore(partie.scores);
	sauvegarder();
	statistiques.sauvegarder();
}

void Jeu :: initialisationPartie()
{
	partie.initialisation();
}

void Jeu :: bouclePartie(const char c)
{
	if (c=='0')
		menu=0;
	else
	{
		int dep=4;
		if (partie.personnage.getBonus()==2 && partie.personnage.getFinBonus()>=partie.scores.temps)
			dep=2*dep;
		switch (c)
		{
			case 'z': partie.deplacementPersonnage(0, -dep);break;
			case 's': partie.deplacementPersonnage(0, dep);break;
			case 'q': partie.deplacementPersonnage(-dep, 0);break;
			case 'd': partie.deplacementPersonnage(dep, 0);break;
			default:break;
		}
		partie.mouvementTerrain();
		partie.scores.temps+=0.1;
		partie.personnage.setAnimation(int(10*partie.scores.temps)%4);
	}
	if (!partie.vivant)
	{
		finPartie();
		menu=-1;
	}
}

void Jeu :: boucleMenu(const char c[3])
{
	if (c[2]=='1')
		switch (c[0])
		{
			case '0':menu=-2;break;
			case '1':
			{
				menu=1;
				initialisationPartie();
			}break;
			case '2':menu=2;break;
			case '3':menu=3;break;
			case '4':menu=4;break;
			default:break;
		}
}

void Jeu :: boucleStatique(const char c[3])
{
	if (c[0]=='0' && c[2]=='1')
		menu=0;
}

void Jeu :: boucleBoutique(const char c[3])
{
	if (c[2]=='1'){
		switch (c[0])
		{
			case '0':menu=0;break;
			case 'c':
			{
				if ('0'<c[1] && c[1]-'0'<=int(magasin.getNbCostumes()))
				{
					if (magasin.costumes[c[1]-'0'-1].achete)
						equiperCostume(c[1]-'0'-1);
					else
						magasin.acheterArticle(magasin.costumes[c[1]-'0'-1]);
				}
			}break;
			case 'd':
			{
				if ('0'<c[1] && c[1]-'0'<=int(magasin.getNbDecors()))
				{
					if (magasin.decors[c[1]-'0'-1].achete)
						equiperDecor(c[1]-'0'-1);
					else
						magasin.acheterArticle(magasin.decors[c[1]-'0'-1]);
				}
			}break;
			default:break;
		}
	}
}

void Jeu::boucle(const char c[3])
{
	switch (menu)
	{
		case -1:boucleStatique(c);break;
		case 0:boucleMenu(c);break;
		case 1:bouclePartie(c[0]);break;
		case 2:boucleBoutique(c);break;
		case 3:boucleStatique(c);break;
		case 4:reinitialiser();break;
		default:break;
	}
}

int Jeu::getMenu()const
{
	return menu;
}

void Jeu::testRegression()const
{
	cout<<"Initialisation:";
	Jeu jeuTest;
	jeuTest.partie.testRegression();
	jeuTest.magasin.testRegression();
	jeuTest.statistiques.testRegression();
	cout<<" OK"<<endl;
}

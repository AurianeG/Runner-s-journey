#include "../include/Partie.h"
#include <time.h>
#include <cassert>
#include <iostream>
#include <math.h>

using namespace std;


//Fonction appelé au lancement d'une partie (Pas un constructeur)
void Partie :: initialisation()
{
	srand((unsigned int)time(NULL));
	vivant=true;
	vitesse=3;
	personnage.initialisation(personnage.position.getLargeur(), terrain.getDimy()/2);
	lotObjets.initialisation();
	scores.initialisation();
}

void Partie::mouvementTerrain()	{
	deplacementObjets(-int(vitesse), 0);
	interactionsPersonnage();
	placementObjets();
	scores.distance=scores.distance+int(vitesse);
	if (int(vitesse)<8)
		vitesse+=0.01;
}
	

void Partie::deplacementPersonnage (const int depx, const int depy)	{
   	personnage.position.deplacer(depx,depy);
   	if (personnage.position.x+int(personnage.position.getLargeur()) >= int(terrain.getLargeur())) 
		personnage.position.x = terrain.getLargeur()-personnage.position.getLargeur()-1;	
   	if (int(personnage.position.x-personnage.position.getLargeur()) < 0)
		personnage.position.x = personnage.position.getLargeur();
   	if (personnage.position.y+int(personnage.position.getHauteur())>= int(terrain.getDimy()+terrain.getHauteur())/2)
		personnage.position.y = int(terrain.getDimy()+terrain.getHauteur())/2-personnage.position.getHauteur()-1;
   	if (personnage.position.y-int(personnage.position.getHauteur()) < int(terrain.getDimy()-terrain.getHauteur())/2)
		personnage.position.y = int(terrain.getDimy()-terrain.getHauteur())/2+personnage.position.getHauteur();
}

void Partie::deplacementObjets(const int depx, const int depy)	{
	for (int i=0;i<int(lotObjets.getNbObjets());i++)
	{
		lotObjets.objets[i].position.deplacer(depx,depy);
		if (lotObjets.objets[i].position.x+int(lotObjets.objets[i].position.getLargeur())<0)
		{
			lotObjets.delObjet(i);
			i--;
		}
	}
}
	
// Selectionne les objets à placer sur le terrain
void Partie::placementObjets(){
	if (int(scores.distance)%60<int(vitesse))
		placementObjet(3, rand()%2);
	if (int(scores.distance)%120<int(vitesse))
		placementObjet(3, 2+rand()%(lotObjets.getNbObstacles()-2));
	if (int(scores.distance+1)%300<int(vitesse) && personnage.getFinBonus()<scores.temps)
		placementObjet(1,rand()%lotObjets.getNbBonus());
	if (int(scores.distance)%40<int(vitesse))
		placementObjet(2, 0);
}

// Place un objet sur le terrain
void Partie::placementObjet(const unsigned int tp, const unsigned int tps)	{
	lotObjets.addObjet(tp,tps);
	Objet * o=&lotObjets.objets[lotObjets.getNbObjets()-1];
	int min,max,nombreDeValeurs;
	if (tp==3 && tps<2) {
		min=o->position.getHauteur();
		max=(terrain.getDimy()-terrain.getHauteur())/2-2*o->position.getHauteur();
		nombreDeValeurs=min+rand()%max;
		o->position.y = (rand()%2)*((terrain.getDimy()+terrain.getHauteur())/2)+nombreDeValeurs;
	}
	else {
		min = (terrain.getDimy()-terrain.getHauteur())/2+o->position.getHauteur(); 
		max = terrain.getDimy()-(terrain.getDimy()-terrain.getHauteur())/2-o->position.getHauteur();
		nombreDeValeurs = max - min;
 		o->position.y = (rand() % nombreDeValeurs) + min;
	}
	o->position.x = terrain.getDimx();
	bool effacer=0;
	Objet * obj2;
	for (unsigned int j=int(o->position.y-int(o->position.getHauteur())); int(j)<int(o->position.y+int(o->position.getHauteur()))+1;j++)
	{
		for (unsigned int i=int(o->position.x-int(o->position.getLargeur())); int(i)<int(o->position.x+int(o->position.getLargeur())+1);i++)
		{
			for (unsigned int k=0;k<lotObjets.getNbObjets()-1;k++)
			{
				obj2=&lotObjets.objets[k];
				if (obj2->position.y-int(obj2->position.getHauteur())<=int(j) && 
				obj2->position.y+int(obj2->position.getHauteur())>=int(j) && 
				obj2->position.x-int(obj2->position.getLargeur())<=int(i) &&
				obj2->position.x+int(obj2->position.getLargeur())>=int(i))
					effacer=1;
			}
		}
	}
	if (effacer)
		lotObjets.delObjet(lotObjets.getNbObjets()-1);
}
	

void Partie::interactionsPersonnage()	{
	Objet * obj;
	for (unsigned int j=max(int(0),personnage.position.y-int(personnage.position.getHauteur())); int(j)<min(int(terrain.getDimy()),personnage.position.y+int(personnage.position.getHauteur())+1);j++)
	{
		for (unsigned int i=max(int(0),personnage.position.x-int(personnage.position.getLargeur())); int(i)<min(int(terrain.getLargeur()),personnage.position.x+int(personnage.position.getLargeur())+1);i++)
		{
			for (unsigned int k=0;k<lotObjets.getNbObjets();k++)
			{
				obj=&lotObjets.objets[k];
				if (obj->getType()==2 && personnage.getBonus()==1 && personnage.getFinBonus()>=scores.temps)
				{
					if (int(obj->position.y-2*personnage.position.getHauteur()-obj->position.getHauteur())<=int(j) && 
					int(obj->position.y+2*personnage.position.getHauteur()+obj->position.getHauteur())>=int(j) && 
					int(obj->position.x-2*personnage.position.getLargeur()-obj->position.getLargeur())<=int(i) &&
					int(obj->position.x+2*personnage.position.getLargeur()+obj->position.getLargeur())>=int(i))
					{
						scores.pieces++;
						lotObjets.delObjet(k);
						k--;
						scores.score+=10;
					}
				}
				else
					if (obj->position.y-int(obj->position.getHauteur())<=int(j) && 
					obj->position.y+int(obj->position.getHauteur())>=int(j) && 
					obj->position.x-int(obj->position.getLargeur())<=int(i) &&
					obj->position.x+int(obj->position.getLargeur())>=int(i))
						switch (obj->getType())
						{	
							case 1: //bonus
							{
								recupBonus(obj->getTypeSecondaire());
								lotObjets.delObjet(k);
								k--;
								scores.score+=50;
							}break;
							case 2: //piece
							{
								scores.pieces++;
								lotObjets.delObjet(k);
								k--;
								scores.score+=10;
							}break;
							case 3: //obstacle
							if(personnage.getBonus()!=0 || personnage.getFinBonus()<scores.temps)
								vivant=false;
							break;
							default:break;
						}
			}
		}
	}
}

void Partie::recupBonus(const unsigned int typeSecondaire)	{
	personnage.setBonus(typeSecondaire);
	personnage.setFinBonus(lotObjets.dureeBonus[typeSecondaire]+scores.temps);
} 

void Partie::testRegression()const
{
	cout<<"Initialisation ";
	Partie partieTest;
	partieTest.terrain.testRegression();
	partieTest.lotObjets.testRegression();
	cout<<" OK"<<endl;
}

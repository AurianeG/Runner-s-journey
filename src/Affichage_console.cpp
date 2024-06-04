#include "../include/Affichage_console.h"
#include <iostream>
#include <fstream>
using namespace std;

void Affichage_console::afficher(const Jeu & jeu)
{
	switch (jeu.getMenu())
	{
		case -1:afficherFinPartie(jeu);break;
		case 0:afficherMenu();break;
		case 1:afficherPartie(jeu);break;
		case 2:afficherBoutique(jeu);break;
		case 3:afficherStatistiques(jeu);break;
	}
}

void Affichage_console::placementCollision(int ** tab,const Jeu & jeu){
	Objet * obj;
	for (unsigned int j=0;j<jeu.partie.terrain.getDimy();j++)
		for (unsigned int i=0;i<jeu.partie.terrain.getLargeur();i++)
			tab[j][i]=-1;
	for (unsigned int i1=0;i1<jeu.partie.lotObjets.getNbObjets();i1++)
	{
		obj=&jeu.partie.lotObjets.objets[i1];
		for (unsigned int j=max(0,int(obj->position.y-obj->position.getHauteur()));
		j<min(jeu.partie.terrain.getDimy(),obj->position.y+obj->position.getHauteur()+1);j++)
			for (unsigned int i=max(0,int(obj->position.x-obj->position.getLargeur()));
			i<min(jeu.partie.terrain.getLargeur(),obj->position.x+obj->position.getLargeur()+1);i++)
				tab[j][i]=obj->getType();	
	}
	for (unsigned int j=max(0,int(jeu.partie.personnage.position.y-jeu.partie.personnage.position.getHauteur())); j<min(jeu.partie.terrain.getDimy(),jeu.partie.personnage.position.y+jeu.partie.personnage.position.getHauteur()+1);j++)
		for (unsigned int i=max(0,int(jeu.partie.personnage.position.x-jeu.partie.personnage.position.getLargeur())); i<min(jeu.partie.terrain.getLargeur(),jeu.partie.personnage.position.x+jeu.partie.personnage.position.getLargeur()+1);i++)
			tab[j][i]=0;
}

void Affichage_console::afficherPartie(const Jeu & jeu)
{
	for (int i=0;i<20;i++)
		cout<<endl;
    cout<<"Distance: "<<jeu.partie.scores.distance<<" Score: "<<jeu.partie.scores.score<<" Pieces: "<<jeu.partie.scores.pieces<<endl;
    int ** tab=new int * [jeu.partie.terrain.getDimy()];
    for (unsigned int i=0;i<jeu.partie.terrain.getDimy();i++)
    	tab[i]=new int [jeu.partie.terrain.getLargeur()];
    placementCollision(tab,jeu);
    if (jeu.partie.personnage.getFinBonus()>jeu.partie.scores.temps)
    {
    	switch (jeu.partie.personnage.getBonus())
    	{
    		case 0:cout<<"Invincibilité ";break;
    		case 1:cout<<"Aimant ";break;
    		case 2:cout<<"Vitesse ";break;
    		default:break;
    	}
    	cout<<int(10*(jeu.partie.personnage.getFinBonus()-jeu.partie.scores.temps))/10.0<<" s";
    }
    cout<<endl;
    for (unsigned int j = 0; j < jeu.partie.terrain.getDimy(); j++)
    {
        for (unsigned int i = 0; i < jeu.partie.terrain.getLargeur(); i++)
        {
            if (tab[j][i]==-1)
            {
                if (int(jeu.partie.terrain.getDimy()-jeu.partie.terrain.getHauteur())/2<=int(j) && int(j)<int(jeu.partie.terrain.getDimy()+jeu.partie.terrain.getHauteur())/2)
                    cout<<" ";
                else
                    cout<<"*";
            }
            else
                cout<<tab[j][i];
        }
        cout << endl;
    }
    for (unsigned int i=0;i<jeu.partie.terrain.getDimy();i++)
    	delete [] tab[i];
    delete [] tab;
}

void Affichage_console::afficherFinPartie(const Jeu & jeu)
{
	for (int i=0;i<50;i++)
		cout<<endl;
	cout<<"Fin de partie"<<endl<<endl;
	cout<<"Score obtenue: "<<jeu.partie.scores.score<<endl;
	cout<<"Distance parcourue: "<<jeu.partie.scores.distance<<endl;
	cout<<"Pieces recuperes: "<<jeu.partie.scores.pieces<<endl;
	cout<<"Total des pieces: "<<jeu.magasin.pieces<<endl<<endl;
}

void Affichage_console::afficherMenu()
{
	for (int i=0;i<50;i++)
		cout<<endl;
	cout<<"Menu"<<endl<<endl;
	cout<<"1 Lancer une partie"<<endl;
	cout<<"2 Boutique"<<endl;
	cout<<"3 Statistiques"<<endl;
	cout<<"4 Reinitialiser"<<endl;
	cout<<"0 Quitter"<<endl<<endl;
}

void Affichage_console::afficherStatistiques(const Jeu & jeu)
{
	for (int i=0;i<50;i++)
		cout<<endl;
	cout<<"Statistiques"<<endl<<endl;
	cout<<"Nombre parties jouees: "<<jeu.statistiques.getNbScores()<<endl<<endl;
	Scores scr;
	scr=jeu.statistiques.total();
	cout<<"Nombre total de pieces recuperees: "<<scr.pieces<<endl;
	cout<<"Distance total parcourue: "<<scr.distance<<endl;
	cout<<"Score total: "<<scr.score<<endl<<endl;
	scr=jeu.statistiques.moyenne();
	cout<<"Nombre moyen de pieces recuperees: "<<scr.pieces<<endl;
	cout<<"Distance moyenne parcourue: "<<scr.distance<<endl;
	cout<<"Score moyen: "<<scr.score<<endl<<endl;
	scr=jeu.statistiques.max();
	cout<<"Nombre maximum de pieces recuperees: "<<scr.pieces<<endl;
	cout<<"Distance maximal parcourue: "<<scr.distance<<endl;
	cout<<"Meilleur score: "<<scr.score<<endl<<endl;
	cout<<"0 Retour"<<endl<<endl;
}


void Affichage_console::afficherBoutique(const Jeu & jeu)
{
	for (int i=0;i<50;i++)
		cout<<endl;
	cout<<"Boutique"<<endl<<endl;
	cout<<"Pieces: "<<jeu.magasin.pieces<<endl<<endl;
	cout<<"costumes:"<<endl;
	for (unsigned int i=0;i<jeu.magasin.getNbCostumes();i++)
	{
		cout<<"c"<<i+1<<" "<<jeu.magasin.costumes[i].nom<<" ";
		if (jeu.magasin.costumes[i].achete)
		{
			cout<<"(achete)";
			if (jeu.partie.personnage.getCostume()==i)
				cout<<"(equipe)";
			cout<<endl;
		}
		else
			cout<<"("<<jeu.magasin.costumes[i].prix<<" pieces)"<<endl;
	}
	cout<<endl;
	cout<<"decors:"<<endl;
	for(unsigned int i=0;i<jeu.magasin.getNbDecors();i++)
	{
		cout<<"d"<<i+1<<" "<<jeu.magasin.decors[i].nom<<" ";
		if (jeu.magasin.decors[i].achete)
		{
			cout<<"(achete)";
			if (jeu.partie.terrain.getDecor()==i)
				cout<<"(equipe)";
			cout<<endl;
		}
		else
			cout<<"("<<jeu.magasin.decors[i].prix<<" pieces)"<<endl;
	}
	cout<<endl<<"0 Retour"<<endl<<endl;
}



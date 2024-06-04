#include "../include/Magasin.h"
#include <fstream>
#include <iostream>
#include<cassert>

Magasin :: Magasin()
{
    costumes=NULL;
    decors=NULL;
    nbCostumes=0;
    nbDecors=0;
    chargerCostumes();
    chargerDecors();
}

Magasin :: ~Magasin()
{
    if (costumes!=NULL)
        delete [] costumes;
    if (decors!=NULL)
        delete [] decors;
}

void Magasin :: chargerCostumes()
{
    if (costumes!=NULL)
        delete [] costumes;
    ifstream fichier("./data/textes/données/costumes.txt");
	assert(fichier.is_open());
	string mot;
	fichier>>mot>>nbCostumes;
    costumes=new Article [nbCostumes];
    for (unsigned int i=0; i<nbCostumes; i++)
    {
        fichier>>mot>>costumes[i].nom>>mot>>costumes[i].prix;
        costumes[i].achete=0;
    }
    fichier.close();
}

void Magasin :: chargerDecors()
{
    if (decors!=NULL)
        delete [] decors;
    ifstream fichier("./data/textes/données/décors.txt");
	assert(fichier.is_open());
	string mot;
	fichier>>mot>>nbDecors;
    decors=new Article [nbDecors];
    for (unsigned int i=0; i<nbDecors; i++)
    {
        fichier>>mot>>decors[i].nom>>mot>>decors[i].prix;
        decors[i].achete=0;
    }
    fichier.close();
}

void Magasin :: acheterArticle(Article & article)
{
    if (article.achete==false && article.prix<=pieces)
    {
        article.achete=true;
        pieces=pieces-article.prix;
    }
}

unsigned int Magasin :: getNbCostumes()const
{
    return nbCostumes;
}

unsigned int Magasin :: getNbDecors()const
{
    return nbDecors;
}

void Magasin :: testRegression()const
{
	std::cout<<"Initialisation:";
	Magasin magasinTest;
	assert(magasinTest.getNbCostumes()>0 && magasinTest.getNbDecors()>0);
	std::cout<<" OK"<<std::endl<<"acheterArticle():";
	magasinTest.costumes[0].prix=100;
	magasinTest.costumes[0].achete=false;
	magasinTest.pieces=99;
	magasinTest.acheterArticle(magasinTest.costumes[0]);
	assert(magasinTest.costumes[0].achete==false && magasinTest.pieces==99);
	magasinTest.pieces=100;
	magasinTest.acheterArticle(magasinTest.costumes[0]);
	assert(magasinTest.costumes[0].achete==true && magasinTest.pieces==0);
	std::cout<<" OK"<<std::endl;
}



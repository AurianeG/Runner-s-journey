#include "../include/Jeu_console.h"
#include <iostream>
using namespace std;

void Jeu_console :: getEvenements(char c[3])
{
	cin>>c;
	c[2]='1';
}

void Jeu_console :: lancement()
{
	char choix[3];
	do
	{
		affCons.afficher(jeu);
		getEvenements(choix);
		jeu.boucle(choix);
	}while (jeu.getMenu()!=-2);
}


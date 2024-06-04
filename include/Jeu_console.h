#ifndef _JEU_CONSOLE
#define _JEU_CONSOLE

#include "Affichage_console.h"

/**
@brief classe Jeu_console
**/

class Jeu_console
{
private:
	Jeu jeu; //!< definit le jeu
	Affichage_console affCons; //!< definit l'affichage

/**
@brief getEvenements: récupère les évenements
@param char c[3] tableau à remplir avec les évenements
**/
	void getEvenements(char c[3]);

public:
/**
@brief lancement: lance le jeu
@param none
**/
	void lancement();

};

#endif

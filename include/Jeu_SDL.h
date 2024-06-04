#ifndef _JEU_SDL
#define _JEU_SDL

#include "Affichage_SDL.h"

/**
@brief classe Jeu_SDL
**/

class Jeu_SDL
{
private:
	Jeu jeu; //!< definit le jeu
	Affichage_SDL affSDL{jeu}; //!< definit l'affichage
	bool quitter=0; //!< definit si il faut fermer la fenetre SDL

/**
@brief getEvenement: rempli le tableau avec les évenements
@param char c[3] renvoie les évenements	
**/
void getEvenements(char c[3]);
	
/**
@brief evenement : renvoie les information concernant la souris et le clavier
@param char touche renvoie la touche préssée ou - si aucune touche est préssée
@param int posx renvoie la coordonnée horizontale de la souris
@param int posy renvoie la coordonnée verticale de la souris
@return bool renvoie si le clic gauche est préssé
**/
	bool evenement(char & touche, int & posx, int & posy);
	
/**
@brief evenementMenu : renvoie les information concernant le Menu
@param char resultat renvoie la valeur de l'action
@return bool renvoie si l'action est à réaliser;
**/
	void evenementMenu(char resultat[3]);
	
/**
@brief evenementJeu : renvoie les information concernant le jeu
@param char resultat renvoie la valeur de l'action
**/
	void evenementPartie(char resultat[3]);
	
/**
@brief evenementMenuStatique: renvoie les information concernant les menu statiques
@param char resultat renvoie la valeur de l'action
@return bool renvoie si l'action est à réaliser;
**/
	void evenementMenuStatique(char resultat[3]);
	
/**
@brief evenementBoutique: renvoie les information concernant la boutique
@param char resultat[2] renvoie la valeur de l'action
@return bool renvoie si l'action est à réaliser;
**/
	void evenementBoutique(char resultat[3]);


public:
/**
@brief lancement : lance le jeu
@param none
**/
	void lancement();

};

#endif

#ifndef _AFFICHAGE_CONSOLE
#define _AFFICHAGE_CONSOLE

#include "Jeu.h"

/**
@brief classe Affichage_console
**/

class Affichage_console
{
public :

/**
@brief afficher: affiche le jeu
@param Jeu jeu le jeu a afficher
**/
    void afficher(const Jeu & jeu);

/**
@brief afficherPartie: affiche le terrain lors d'une partie
@param Jeu jeu le jeu a afficher
**/
    void afficherPartie(const Jeu & jeu);
    
/**
@brief afficherFinPartie: affiche les scores lors de la fin de partie
@param Jeu jeu le jeu a afficher
**/
    void afficherFinPartie(const Jeu & jeu);
    
/**
@brief afficherMenu: affiche les differentes options
@param none
**/
    void afficherMenu();
    
/**
@brief afficherStatistiques: affiche les statistiques des parties précédentes
@param Jeu jeu le jeu a afficher
**/
    void afficherStatistiques(const Jeu & jeu);

/**
@brief afficherBoutique: affiche la boutique
@param Jeu jeu le jeu a afficher
**/
    void afficherBoutique(const Jeu & jeu);
    
private:
	void placementCollision(int ** tab,const Jeu & jeu);
    
};


#endif

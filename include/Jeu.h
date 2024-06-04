#ifndef _JEU
#define _JEU

#include "Partie.h"
#include "Magasin.h"
#include "Statistiques.h"


/**
@brief classe Jeu
**/

class Jeu
{
public:
	Partie partie; //!< definit la partie
	Magasin magasin; //!< definit le magasin
	Statistiques statistiques; //!< definit les statistiques

/**
@brief constructeur de la classe
@param none
**/
	Jeu();
	
/**
@brief getMenu: accesseur de menu
**/
	int getMenu()const;
	
/**
@brief boucle: gère le jeu
@param char c[3] les évenements
**/
	void boucle(const char c[3]);
	
/**
@brief testRegression : teste le bon fonctionnement de la classe
@param none
**/
	void testRegression()const;

private:
	int menu; //!< definit le menu actuel

/**
@brief bouclePartie: gère une partie
@param char c la touche pressée
**/
	void bouclePartie(const char c);

/**
@brief boucleMenu: gère les differents menus
@param char c[3] les évenements
**/
	void boucleMenu(const char c[3]);
	
/**
@brief boucleStatique: gère une page statique
@param char c[3] les évenements
**/
	void boucleStatique(const char c[3]);
	
/**
@brief boucleBoutique: gère la boutique
@param char c[3] les évenements
**/
	void boucleBoutique(const char c[3]);
	
/**
@brief reinitialiser: réinitialise les données et les statistiques
@param none
**/
	void reinitialiser();

/**
@brief sauvegarder: sauvegarde le nombre de pièces les costumes et les décors équipés et achetés dans un fichier texte
@param none
**/
	void sauvegarder()const;
	
/**
@brief charger: charge les données à partir d'un fichier texte
@param none
**/
	void charger();
	
/**
@brief initialisationPartie: debute une partie
@param none
**/
	void initialisationPartie();
	
/**
@brief equiperCostume: equipe le costume correspondant à cet indice
@param unsigned int costume correspond à l'indice du costume à équiper
**/
	void equiperCostume(const unsigned int costume);
	
/**
@brief equiperDecor: equipe le decor correspondant à cet indice
@param unsigned int decor correspond à l'indice du décor à équiper
**/
	void equiperDecor(const unsigned int decor);
	
/**
@brief finPartie: récupere les pièces de la partie et sauvegarde les données et les statistiques
@param none
**/
	void finPartie();

};

#endif

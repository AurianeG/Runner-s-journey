#ifndef _PARTIE
#define _PARTIE

#include "Personnage.h"
#include "Terrain.h"
#include "Lot_objets.h"
#include "Scores.h"

/**
@brief classe Partie
**/

class Partie
{
public:
	Personnage personnage; //!< definit le joueur
	Terrain terrain; //!< definit le terrain
	Scores scores; //!< definit les scores de la partie
	Lot_objets lotObjets; //!< definit l'ensemble des objets du jeu
	bool vivant; //!< definit si le joueur est en vie ou non
	

/**
@brief initialisation: initialise la partie
@param none
**/
	void initialisation();

/**
@brief mouvementTerrain: déplace les objets et gère les interactions
@param none
**/
	void mouvementTerrain();
	
/**
@brief deplacementPersonnage: déplace le personnage sur le terrain
@param int depx correspond au mouvement horizontal
@param int depy correspond au mouvement vertical
**/
	void deplacementPersonnage (const int depx, const int depy);

/**
@brief testRegression : teste le bon fonctionnement de la classe
@param none
**/
	void testRegression()const;
	
private:
	float vitesse; //!< definit la vitesse de défillement des objets
	
/**
@brief deplacementObjets: déplace l'ensemble des objets de lotObjets.objets
@param int depx correspond au mouvement horizontal
@param int depy correspond au mouvement vertical
**/
	void deplacementObjets(const int depx, const int depy);

/**
@brief placementObjets: choisit les objets à faire apparaitre sur le terrain
@param none
**/
	void placementObjets();

/**
@brief placementObjet: génere un objet sur le terrain et l'ajoute dans lotObjets.objets
@param unsigned int tp correspond au type de l'objet
@param unsigned int tps correspond au type secondaire de l'objet
**/
	void placementObjet(const unsigned int tp, const unsigned int tps);
	
/**
@brief interactionsPersonnage: agit en fonction des types d'objets en collision avec le personnage
@param none
**/
	void interactionsPersonnage();

/**
@brief recupBonus: modifie personnage.bonus et personnage.finBonus lors de la récupération d'un bonus
@param unsigned int type correspond au type de bonus récupéré par le personnage
**/
	void recupBonus(const unsigned int type);

};

#endif

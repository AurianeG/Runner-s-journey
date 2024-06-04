#ifndef _LOT_OBJETS
#define _LOT_OBJETS

#include "Objet.h"
#include "Obstacle.h"

/**
@brief classe Lot_Objets
**/

class Lot_objets
{
private:
	unsigned int nbObjets; //!< definit le nombre d'objets present sur le terrain
	unsigned int capacite; //!< definit la capacité d'objets stockables
	unsigned int nbObstacles; //!< definit le nombre d'obstacle existants
	unsigned int nbBonus; //!< definit le nombre de bonus existants
	
/**
@brief chargerObstacles : charge les dimensions des obstacles prédéfinis dans un fichier texte vers le tableau obstacles
@param none
**/
	void chargerObstacles();

/**
@brief chargerDureeBonus : charge les durées des bonus prédéfinis dans un fichier texte vers le tableau dureeBonus
@param none
**/
	void chargerDureeBonus();
	
public:
	Objet * objets; //!< definit le tableau des objets presents sur le terrain
	Obstacle * obstacles; //!< definit le tableau des dimensions des obstacles
	unsigned int * dureeBonus; //!< definit le tableau des durée des bonus

/**
@brief constructeur de Lot_objets
@param none
**/
	Lot_objets();

/**
@brief destructeur de Lot_objets
@param none
**/
	~Lot_objets();

/**
@brief initialisation : efface tous les objets
@param none
**/
	void initialisation();
	
/**
@brief addObjet : permet d'ajouter un objet au tableau d'objets
@param unsigned int tp correspond au type de l'objet
@param unsigned int tps correspond au type secondaire de l'objet
**/
	void addObjet (const unsigned int tp, const unsigned int tps);

/**
@brief delObjet : permet de supprimer un objet du tableau d'objets
@param unsigned int indice correspond à l'indice de l'objet à supprimer
**/
	void delObjet (const unsigned int indice);
	
/**
@brief accesseur de nbObstacles
@param none
@return unsigned int la taille du tableau obstacles 
**/
	unsigned int getNbObstacles()const;

/**
@brief accesseur de nbBonus
@param none
@return unsigned int la taille du tableau dureeBonus
**/
	unsigned int getNbBonus()const;
	
/**
@brief accesseur de nbObjets
@param none
@return unsigned int la taille du tableau objets
**/
	unsigned int getNbObjets()const;
	
/**
@brief testRegression : teste le bon fonctionnement de la classe
@param none
**/
	void testRegression()const;

};

#endif

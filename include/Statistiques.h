#ifndef _STATISTIQUES
#define _STATISTIQUES

#include "Scores.h"

/**
@brief classe Statistiques
**/

class Statistiques
{
private:
	unsigned int nbScores; //!< definit le nombre de scores dans le tableau de scores
	unsigned int capacite; //!< definit la taille du tableau de scores
	
public:
	Scores * scoresParties; //!< definit le tableau des scores précédents
	
/**
@brief constructeur de Statistiques
@param none
**/
	Statistiques();
	
/**
@brief destructeur de Statistiques
@param none
**/
	~Statistiques();

/**
@brief sauvegarder: sauvegarde le tableau de scores dans un fichier texte
@param none
**/
	void sauvegarder()const;
	
/**
@brief charger: charge le tableau de scores à partir d'un fichier texte
@param none
**/
	void charger();
	
/**
@brief reinitialiser: Efface les scores
@param none
**/
	void reinitialiser();
	
/**
@brief addScore: ajoute un score
@param Scores &score correspond au score à rajouter
**/
	void addScore(const Scores & score);
	
/**
@brief moyenne: renvoie le score moyen
@param none
@return Scores les différentes valeurs des scores
**/
	Scores moyenne()const;

/**
@brief max: renvoie le score maximal obtenu dans une partie
@param none
@return Scores les différentes valeurs des scores
**/	
	Scores max()const;

/**
@brief total: renvoie le score total
@param none
@return Scores les différentes valeurs des scores
**/	
	Scores total()const;

/**
@brief accesseur de nbScores
@param none
@return unsigned int le nombre de scores
**/	
	unsigned int getNbScores()const;

/**
@brief testRegression: test le bon fonctionnement de la classe
@param none
**/
	void testRegression()const;

};

#endif

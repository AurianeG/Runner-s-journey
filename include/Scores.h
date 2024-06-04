#ifndef _SCORES
#define _SCORES

/**
@brief classe Scores
**/

class Scores
{
public:
	unsigned int score; //!< definit le score de la partie
	unsigned int distance; //!< definit la distance parcourue
	unsigned int pieces; //!< definit le nombre de pièces ramassées
	float temps; //!< definit le temps (s) écoulé depuis le lancement de la partie
	
/**
@brief initialisation: initialise les scores au début d'une partie
@param none
**/
	void initialisation();

/**
@brief calculScore: calcule le score de la partie
@param none
**/
	void calculScore();



};

#endif

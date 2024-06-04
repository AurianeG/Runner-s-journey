#include "../include/Scores.h"
	

void Scores::initialisation()	{
	score = 0 ;
	distance = 0 ;
	pieces = 0 ;
	temps = 0 ;

}

void Scores::calculScore()	{
	score = distance + pieces + temps ;
}


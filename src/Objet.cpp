#include "../include/Objet.h"

Objet::Objet()
{
    type = 0;
    typeSecondaire = 0;
    Position position;
}

Objet::~Objet()
{
    type = 0;
    typeSecondaire = 0;
}

void Objet :: setType (const unsigned int t)
{
	type=t;
}
	
unsigned int Objet :: getType()const
{
	return type;
}
	
void Objet :: setTypeSecondaire (const unsigned int t)
{
	typeSecondaire=t;
}
	
unsigned int Objet :: getTypeSecondaire()const
{
	return typeSecondaire;
}


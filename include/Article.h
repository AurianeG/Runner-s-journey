#ifndef _ARTICLE
#define _ARTICLE

#include <iostream>
using namespace std;

/**
@brief classe Article
**/

class Article
{
public:
	bool achete; //!< definit si l'article a été acheté
	unsigned int prix; //!< definit le prix de l'article
	string nom; //!< definit le nom de l'article

	/**
	@brief Article : constructeur de la classe Article
	**/
	Article();
	
};

#endif

#include "../include/Affichage_SDL.h"
#include<cassert>

Affichage_SDL::Affichage_SDL(const Jeu & jeu)
{
    	assert(SDL_Init(SDL_INIT_VIDEO) == 0);
    	window = SDL_CreateWindow("Runner's Journey", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, TAILLEX, TAILLEY, SDL_WINDOW_SHOWN);
    	assert(window != NULL);
    	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    	assert(renderer != NULL);
    	char nom[100];
    	nbPersonnages=jeu.magasin.getNbCostumes();
    	for (unsigned int j=0;j<nbPersonnages;j++)
    		for (unsigned int i=0;i<4;i++)
    		{
    			fusion_texte(nom,"./data/img/personnage/", jeu.magasin.costumes[j].nom, to_string(i));
			personnages[j][i]=SDL_LoadBMP(nom);
			assert(personnages[j][i]!=NULL);
		}
	nbDecors=jeu.magasin.getNbDecors();
    	for (unsigned int j=0;j<nbDecors;j++)
    	{
    		fusion_texte(nom,"./data/img/décor/", jeu.magasin.decors[j].nom, "fond");
		decors[j][0]=SDL_LoadBMP(nom);
		assert(decors[j][0]!=NULL);
    		for (unsigned int i=0;i<4;i++)
    		{
    			fusion_texte(nom,"./data/img/décor/", jeu.magasin.decors[j].nom, to_string(i));
			decors[j][i+1]=SDL_LoadBMP(nom);
			assert(decors[j][i+1]!=NULL);
		}
	}
	nbMenus=4;
	fusion_texte(nom,"./data/img/","menu","Menu");
	menus[0]=SDL_LoadBMP(nom);
	assert(menus[0]!=NULL);
	fusion_texte(nom,"./data/img/","menu","Boutique");
	menus[1]=SDL_LoadBMP(nom);
	assert(menus[1]!=NULL);
	fusion_texte(nom,"./data/img/","menu","Statistiques");
	menus[2]=SDL_LoadBMP(nom);
	assert(menus[2]!=NULL);
	fusion_texte(nom,"./data/img/","menu","FinPartie");
	menus[3]=SDL_LoadBMP(nom);
	assert(menus[3]!=NULL);
	nbBoutons=6;
	fusion_texte(nom,"./data/img/","bouton","Jouer");
	boutons[0][0]=SDL_LoadBMP(nom);
	assert(boutons[0][0]!=NULL);
	fusion_texte(nom,"./data/img/","bouton","Jouer_p");
	boutons[0][1]=SDL_LoadBMP(nom);
	assert(boutons[0][1]!=NULL);
	fusion_texte(nom,"./data/img/","bouton","Boutique");
	boutons[1][0]=SDL_LoadBMP(nom);
	assert(boutons[1][0]!=NULL);
	fusion_texte(nom,"./data/img/","bouton","Boutique_p");
	boutons[1][1]=SDL_LoadBMP(nom);
	assert(boutons[1][1]!=NULL);
	fusion_texte(nom,"./data/img/","bouton","Statistiques");
	boutons[2][0]=SDL_LoadBMP(nom);
	assert(boutons[2][0]!=NULL);
	fusion_texte(nom,"./data/img/","bouton","Statistiques_p");
	boutons[2][1]=SDL_LoadBMP(nom);
	assert(boutons[2][1]!=NULL);
	fusion_texte(nom,"./data/img/","bouton","Réinitialiser");
	boutons[3][0]=SDL_LoadBMP(nom);
	assert(boutons[3][0]!=NULL);
	fusion_texte(nom,"./data/img/","bouton","Réinitialiser_p");
	boutons[3][1]=SDL_LoadBMP(nom);
	assert(boutons[3][1]!=NULL);
	fusion_texte(nom,"./data/img/","bouton","Retour");
	boutons[4][0]=SDL_LoadBMP(nom);
	assert(boutons[4][0]!=NULL);
	fusion_texte(nom,"./data/img/","bouton","Retour_p");
	boutons[4][1]=SDL_LoadBMP(nom);
	assert(boutons[4][1]!=NULL);
	fusion_texte(nom,"./data/img/","bouton","Vide");
	boutons[5][0]=SDL_LoadBMP(nom);
	assert(boutons[5][0]!=NULL);
	fusion_texte(nom,"./data/img/","bouton","Vide_p");
	boutons[5][1]=SDL_LoadBMP(nom);
	assert(boutons[5][1]!=NULL);
	nbObjets=2;
	fusion_texte(nom,"./data/img/","objet","Bonus");
	objets[0]=SDL_LoadBMP(nom);
	assert(objets[0]!=NULL);
	fusion_texte(nom,"./data/img/","objet","Pièce");
	objets[1]=SDL_LoadBMP(nom);
	assert(objets[1]!=NULL);
	nbBonus=jeu.partie.lotObjets.getNbBonus();
	for (unsigned int i=0;i<nbBonus;i++)
	{
		fusion_texte(nom,"./data/img/","bonus",to_string(i));
		bonus[i]=SDL_LoadBMP(nom);
		assert(bonus[i]!=NULL);
	}
	for (unsigned int i=0;i<10;i++)
	{
		fusion_texte(nom,"./data/img/","chiffre",to_string(i));
		chiffres[i]=SDL_LoadBMP(nom);
		assert(chiffres[i]!=NULL);
	}
}

void Affichage_SDL::fusion_texte (char nom [100], const string & src1, const string & src2, const string & img)
{
	string n=src1;
	n.append(src2);
	n.append("/");
	n.append(img);
	n.append(".bmp");
	strcpy(nom, n.c_str());
}

Affichage_SDL::~Affichage_SDL()
{
	for (unsigned int j=0;j<nbPersonnages;j++)
    		for (unsigned int i=0;i<4;i++)
    			SDL_FreeSurface(personnages[j][i]);
    	for (unsigned int j=0;j<nbDecors;j++)
    		for (unsigned int i=0;i<5;i++)
    			SDL_FreeSurface(decors[j][i]);
    	for (unsigned int i=0;i<nbMenus;i++)
    		SDL_FreeSurface(menus[i]);
    	for (unsigned int j=0;j<nbBoutons;j++)
    		for (unsigned int i=0;i<1;i++)
    			SDL_FreeSurface(boutons[j][i]);
    	for (unsigned int i=0;i<nbObjets;i++)
    		SDL_FreeSurface(objets[i]);
    	for (unsigned int i=0;i<nbBonus;i++)
    		SDL_FreeSurface(bonus[i]);
    	SDL_DestroyRenderer(renderer);
    	SDL_DestroyWindow(window);
    	SDL_Quit();
}

void Affichage_SDL::placer_image (const Jeu & jeu,SDL_Surface * surface, const Position &pos)
{
	assert(surface!=NULL);
	SDL_Texture *texture=NULL;
	texture=SDL_CreateTextureFromSurface(renderer,surface);
	assert(texture!=NULL);
	const Terrain * ter=&jeu.partie.terrain;
	SDL_Rect position={int((TAILLEX*(pos.x-int(1/2.0+pos.getLargeur()))))/int(ter->getLargeur()),
		int((TAILLEY*(pos.y-int(1/2.0+pos.getHauteur()))))/int(ter->getDimy()),
		int(TAILLEX*(int(1+2.0*pos.getLargeur())))/int(ter->getLargeur()),
		int(TAILLEY*(int(1+2.0*pos.getHauteur())))/int(ter->getDimy())};
	SDL_RenderCopy(renderer,texture,NULL,&position);
	SDL_DestroyTexture(texture);
}

void Affichage_SDL::placer_image (SDL_Surface * surface, const unsigned int x, const unsigned int y, const unsigned int largeur, const unsigned int hauteur)
{
	assert(surface!=NULL);
	SDL_Texture *texture=NULL;
	texture=SDL_CreateTextureFromSurface(renderer,surface);
	assert(texture!=NULL);
	SDL_Rect position={int(TAILLEX*x/100.0-1/2.0*largeur),
		int(TAILLEY*y/100.0-1/2.0*hauteur),
		int(largeur),
		int(hauteur)};
	SDL_RenderCopy(renderer,texture,NULL,&position);
	SDL_DestroyTexture(texture);
}

void Affichage_SDL::afficher(const Jeu & jeu, const char c[3])
{
	switch (jeu.getMenu())
	{
		case -1:afficherFin(jeu, c[0]);break;
		case 0:afficherMenu(c[0]);break;
		case 1:afficherPartie(jeu);break;
		case 2:afficherBoutique(jeu, c);break;
		case 3:afficherStatistiques(jeu, c[0]);break;
	}
}

void Affichage_SDL::afficherPartie(const Jeu & jeu)
{
	SDL_RenderClear(renderer);
	afficherFond(jeu);
	afficherPersonnage(jeu);
	SDL_RenderPresent(renderer);
}

void Affichage_SDL::afficherPersonnage(const Jeu & jeu)
{
	placer_image(jeu,personnages[jeu.partie.personnage.getCostume()][jeu.partie.personnage.getAnimation()],jeu.partie.personnage.position);
}

void Affichage_SDL::afficherMenu(const char bouton)
{
	SDL_RenderClear(renderer);
	placer_image(menus[0],50,50,TAILLEX,TAILLEY);
	if (bouton=='1')
		placer_image(boutons[0][1],50,40,189,50);
	else
		placer_image(boutons[0][0],50,40,189,50);
	if (bouton=='2')
		placer_image(boutons[1][1],50,50,189,50);
	else
		placer_image(boutons[1][0],50,50,189,50);
	if (bouton=='3')
		placer_image(boutons[2][1],50,60,189,50);
	else
		placer_image(boutons[2][0],50,60,189,50);
	if (bouton=='4')
		placer_image(boutons[3][1],50,70,189,50);
	else
		placer_image(boutons[3][0],50,70,189,50);
	SDL_RenderPresent(renderer);
}

//Renvoie le nombre de chiffres qui composent le nombre
unsigned int Affichage_SDL::getLongueur(const unsigned int nombre)
{
	if (nombre==0)
		return 1;
	float num=nombre;
	int compt=0;
	while (num>=1){
		num=num/10.0;
		compt++;
	}
	return compt;
}

void Affichage_SDL::afficherFond (const Jeu & jeu)
{
	placer_image(decors[jeu.partie.terrain.getDecor()][0],50,50,TAILLEX,TAILLEY);
	for (unsigned int i=0;i<jeu.partie.lotObjets.getNbObjets();i++)
	{
		Objet * obst= &jeu.partie.lotObjets.objets[i];
		switch (obst->getType())
		{
			case 1:placer_image(jeu,objets[0],obst->position);break;
			case 2:placer_image(jeu,objets[1],obst->position);break;
			case 3:placer_image(jeu,decors[jeu.partie.terrain.getDecor()][obst->getTypeSecondaire()+1],obst->position);break;
		}
	}
	string chif=to_string(jeu.partie.scores.score);
	for (unsigned int i=0;i<getLongueur(jeu.partie.scores.score);i++)
		placer_image(chiffres[chif[i]-'0'],1+2*i,2,20,20);
	if (jeu.partie.personnage.getFinBonus()>jeu.partie.scores.temps)
	{
		placer_image(bonus[jeu.partie.personnage.getBonus()],2,7,30,30);
		SDL_SetRenderDrawColor(renderer,255-int(255*(jeu.partie.personnage.getFinBonus()-jeu.partie.scores.temps)/10.0),int(255*(jeu.partie.personnage.getFinBonus()-jeu.partie.scores.temps)/10.0),0,255);
		SDL_Rect barre={int(4/100.0*TAILLEX), int(5/100.0*TAILLEY),int((jeu.partie.personnage.getFinBonus()-jeu.partie.scores.temps)/100.0*TAILLEX),25};
		SDL_RenderFillRect(renderer, &barre);
	}
}

void Affichage_SDL::afficherFin(const Jeu & jeu,const char bouton)
{
	SDL_RenderClear(renderer);
	placer_image(menus[3],50,50,TAILLEX,TAILLEY);
	if (bouton=='0')
		placer_image(boutons[4][1],92,95,117,50);
	else
		placer_image(boutons[4][0],92,95,117,50);
	string chif=to_string(jeu.partie.scores.score);
	for (unsigned int i=0;i<getLongueur(jeu.partie.scores.score);i++)
		placer_image(chiffres[chif[i]-'0'],44+3*i,38,30,30);
	chif=to_string(jeu.partie.scores.distance);
	for (unsigned int i=0;i<getLongueur(jeu.partie.scores.distance);i++)
		placer_image(chiffres[chif[i]-'0'],44+3*i,48,30,30);
	chif=to_string(jeu.partie.scores.pieces);
	for (unsigned int i=0;i<getLongueur(jeu.partie.scores.pieces);i++)
		placer_image(chiffres[chif[i]-'0'],44+3*i,58,30,30);
	chif=to_string(jeu.magasin.pieces);
	for (unsigned int i=0;i<getLongueur(jeu.magasin.pieces);i++)
		placer_image(chiffres[chif[i]-'0'],44+3*i,68,30,30);
	SDL_RenderPresent(renderer);
}

void Affichage_SDL::afficherStatistiques(const Jeu & jeu,const char bouton)
{
	SDL_RenderClear(renderer);
	placer_image(menus[2],50,50,TAILLEX,TAILLEY);
	if (bouton=='0')
		placer_image(boutons[4][1],92,95,117,50);
	else
		placer_image(boutons[4][0],92,95,117,50);
	string chif=to_string(jeu.statistiques.getNbScores());
	for (unsigned int i=0;i<getLongueur(jeu.statistiques.getNbScores());i++)
		placer_image(chiffres[chif[i]-'0'],62+2*i,30,22,22);
	Scores scr;
	scr=jeu.statistiques.total();
	chif=to_string(scr.pieces);
	for (unsigned int i=0;i<getLongueur(scr.pieces);i++)
		placer_image(chiffres[chif[i]-'0'],62+2*i,36,22,22);
	chif=to_string(scr.distance);
	for (unsigned int i=0;i<getLongueur(scr.distance);i++)
		placer_image(chiffres[chif[i]-'0'],62+2*i,42,22,22);
	chif=to_string(scr.score);
	for (unsigned int i=0;i<getLongueur(scr.score);i++)
		placer_image(chiffres[chif[i]-'0'],62+2*i,48,22,22);
	scr=jeu.statistiques.moyenne();
	chif=to_string(scr.pieces);
	for (unsigned int i=0;i<getLongueur(scr.pieces);i++)
		placer_image(chiffres[chif[i]-'0'],62+2*i,54,22,22);
	chif=to_string(scr.distance);
	for (unsigned int i=0;i<getLongueur(scr.distance);i++)
		placer_image(chiffres[chif[i]-'0'],62+2*i,60,22,22);
	chif=to_string(scr.score);
	for (unsigned int i=0;i<getLongueur(scr.score);i++)
		placer_image(chiffres[chif[i]-'0'],62+2*i,66,22,22);
	scr=jeu.statistiques.max();
	chif=to_string(scr.pieces);
	for (unsigned int i=0;i<getLongueur(scr.pieces);i++)
		placer_image(chiffres[chif[i]-'0'],62+2*i,72,22,22);
	chif=to_string(scr.distance);
	for (unsigned int i=0;i<getLongueur(scr.distance);i++)
		placer_image(chiffres[chif[i]-'0'],62+2*i,78,22,22);
	chif=to_string(scr.score);
	for (unsigned int i=0;i<getLongueur(scr.score);i++)
		placer_image(chiffres[chif[i]-'0'],62+2*i,84,22,22);
	SDL_RenderPresent(renderer);
}

void Affichage_SDL::afficherBoutique(const Jeu & jeu,const char bouton[3])
{
	SDL_RenderClear(renderer);
	placer_image(menus[1],50,50,TAILLEX,TAILLEY);
	placer_image(objets[1],5,5,30,30);//affiche le nombre de pièce
	string chif=to_string(jeu.magasin.pieces);
	for (unsigned int i=0;i<getLongueur(jeu.magasin.pieces);i++)
		placer_image(chiffres[chif[i]-'0'],10+2*i,5,30,30);
	for (unsigned int i=0;i<nbPersonnages;i++)
	{
		if (bouton[0]=='c' && bouton[1]-'1'==int(i))
			placer_image(boutons[5][1],15*(i+1),42,100,140);
		else
			placer_image(boutons[5][0],15*(i+1),42,100,140);
		placer_image(personnages[i][0],15*(i+1),40,100,100);
		if (jeu.magasin.costumes[i].achete)
		{
			if (i==jeu.partie.personnage.getCostume())
				placer_image(bonus[0],15*(i+1),50,30,30); //mettre un bouton "acheté" ou "possedé"
		}
		else{
			chif=to_string(jeu.magasin.costumes[i].prix);
			for (unsigned int j=0;j<getLongueur(jeu.magasin.costumes[i].prix);j++)
				placer_image(chiffres[chif[j]-'0'],15*(i+1)+2*(j-1),50,30,30);
		}
	}
	for (unsigned int i=0;i<nbDecors;i++)
	{
		if (bouton[0]=='d' && bouton[1]-'1'==int(i))
			placer_image(boutons[5][1],15*(i+1),72,100,140);
		else
			placer_image(boutons[5][0],15*(i+1),72,100,140);
		placer_image(decors[i][1],15*(i+1),70,100,100);
		if (jeu.magasin.decors[i].achete)
		{
			if (i==jeu.partie.terrain.getDecor())
				placer_image(bonus[0],15*(i+1),80,30,30); //mettre un bouton "acheté" ou "possedé"
		}
		else{
			chif=to_string(jeu.magasin.decors[i].prix);
			for (unsigned int j=0;j<getLongueur(jeu.magasin.decors[i].prix);j++)
				placer_image(chiffres[chif[j]-'0'],15*(i+1)+2*(j-1),80,30,30);
		}
	}
	if (bouton[0]=='0')
		placer_image(boutons[4][1],92,95,117,50);
	else
		placer_image(boutons[4][0],92,95,117,50);
	SDL_RenderPresent(renderer);	
}

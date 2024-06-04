#include "../include/Jeu_SDL.h"

bool Jeu_SDL :: evenement(char & touche, int & posx, int & posy)
{
	SDL_Event event;
	bool p=0, c=0;
	if (SDL_PollEvent(&event)){
		do
		{
			switch (event.type)
			{
				case SDL_KEYDOWN:{
					touche=event.key.keysym.sym;
            				p=1;
				}break;
				case SDL_KEYUP:{
					if (touche==event.key.keysym.sym)
						p=0;
				}break;
				case SDL_MOUSEBUTTONDOWN: c=1;break;
				case SDL_WINDOWEVENT:{
					if (event.window.event == SDL_WINDOWEVENT_CLOSE)
						quitter=1;
				}break;
				default:break;
			}
		}while (SDL_PollEvent(&event));
    		if (!p)
    			touche='-';
    	}
    	SDL_GetMouseState(&posx,&posy);
    	return c;
}

void Jeu_SDL :: evenementMenu (char resultat[3])
{
	int x,y;
	bool action=evenement(resultat[0], x, y);
	if (resultat[0]=='b')
	{
		resultat[0]='0';
		resultat[2]='1';
	}
	else
	{
		if (int(affSDL.TAILLEX/2.0-94.5)<=x && x<=int(affSDL.TAILLEX/2.0+94.5))
		{
			if (int(affSDL.TAILLEY*40/100.0-25)<=y && y<=int(affSDL.TAILLEY*40/100.0+25))
				resultat[0]='1';
			if (int(affSDL.TAILLEY*50/100.0-25)<=y && y<=int(affSDL.TAILLEY*50/100.0+25))
				resultat[0]='2';
			if (int(affSDL.TAILLEY*60/100.0-25)<=y && y<=int(affSDL.TAILLEY*60/100.0+25))
				resultat[0]='3';
			if (int(affSDL.TAILLEY*70/100.0-25)<=y && y<=int(affSDL.TAILLEY*70/100.0+25))
				resultat[0]='4';
		}
		if (action)
			resultat[2]='1';
		else
			resultat[2]='0';
	}
}

void Jeu_SDL :: evenementPartie (char resultat[3])
{
	int x,y;
	evenement(resultat[0], x, y);
	if (resultat[0]=='b')
		resultat[0]='0';
}

void Jeu_SDL ::evenementMenuStatique(char resultat[3])
{
	int x,y;
	bool action=evenement(resultat[0], x, y);
	resultat[0]='1';
	if (int(affSDL.TAILLEX*92/100.0-58.5)<=x && x<=int(affSDL.TAILLEX*92/100.0+58.5))
		if (int(affSDL.TAILLEY*95/100.0-25)<=y && y<=int(affSDL.TAILLEY*95/100.0+25))
			resultat[0]='0';
	if (action)
		resultat[2]='1';
	else
		resultat[2]='0';
}

void Jeu_SDL ::evenementBoutique(char resultat[3])
{
	int x,y;
	bool action=evenement(resultat[0], x, y);
	resultat[0]='1';
	if (int(affSDL.TAILLEX*92/100.0-58.5)<=x && x<=int(affSDL.TAILLEX*92/100.0+58.5))
		if (int(affSDL.TAILLEY*95/100.0-25)<=y && y<=int(affSDL.TAILLEY*95/100.0+25))
			resultat[0]='0';
	if (int(affSDL.TAILLEY*42/100.0-70)<=y && y<=int(affSDL.TAILLEY*42/100.0+70))
		for (unsigned int i=0;i<jeu.magasin.getNbCostumes();i++)
		{
			if (int(affSDL.TAILLEX*(15*(i+1))/100.0-50)<=x && x<=int(affSDL.TAILLEX*(15*(i+1))/100.0+50))
			{
				resultat[0]='c';
				resultat[1]='1'+i;
			}
		}
	if (int(affSDL.TAILLEY*72/100.0-70)<=y && y<=int(affSDL.TAILLEY*72/100.0+70))
		for (unsigned int i=0;i<jeu.magasin.getNbDecors();i++)
		{
			if (int(affSDL.TAILLEX*(15*(i+1))/100.0-50)<=x && x<=int(affSDL.TAILLEX*(15*(i+1))/100.0+50))
			{
				resultat[0]='d';
				resultat[1]='1'+i;
			}
		}
	if (action)
		resultat[2]='1';
	else
		resultat[2]='0';
}

void Jeu_SDL :: getEvenements(char c[3])
{
	switch (jeu.getMenu())
	{
		case -1:evenementMenuStatique(c);break;
		case 0:evenementMenu(c);break;
		case 1:evenementPartie(c);break;
		case 2:evenementBoutique(c);break;
		case 3:evenementMenuStatique(c);break;
		default:break;
	}
}

void Jeu_SDL :: lancement()
{
	char choix[3];
	choix[0]='-';
	choix[1]='-';
	choix[2]='0';
	do
	{
		getEvenements(choix);
		jeu.boucle(choix);
		affSDL.afficher(jeu,choix);
		SDL_Delay(100);
	}while (jeu.getMenu()!=-2 && !quitter);
}



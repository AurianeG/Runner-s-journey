#ifndef _AFFICHAGE_SDL
#define _AFFICHAGE_SDL

#include <iostream>
#include <SDL2/SDL.h>
#include "Affichage_SDL.h"
#include "Jeu.h"
using namespace std;

/**
@brief classe Affichage_SDL
**/

class Affichage_SDL
{
private:

SDL_Window * window; //!< definit la fenetre SDL
SDL_Renderer * renderer; //!< definit le renderer de la fenetre SDL
SDL_Surface * personnages[10][4]; //!< definit les images des personnages
unsigned int nbPersonnages; //!< definit le nombre de personnages
SDL_Surface * decors[10][5]; //!< definit les images des decors
unsigned int nbDecors; //!< definit le nombre de decors
SDL_Surface * menus[10]; //!< definit les images des menus
unsigned int nbMenus; //!< definit le nombre de menus
SDL_Surface * boutons[10][2]; //!< definit les images des boutons
unsigned int nbBoutons; //!< definit le nombre de boutons
SDL_Surface * objets[5]; //!< definit les images des objets
unsigned int nbObjets; //!< definit le nombre d'objets
SDL_Surface * bonus[10]; //!< definit les images des bonus
unsigned int nbBonus; //!< definit le nombre de bonus
SDL_Surface * chiffres[10]; //!< definit les images des chiffres

/**
@brief fusion_texte : remplie nom avec le chemin vers l'image à charger
@param char nom [100] correspond au chemin de l'image
@param string src1 correspond au chemin global vers l'image
@param string src2 correspond au chemin plus precis vers l'image
@param string img correspond au nom de l'image à charger
**/
	void fusion_texte (char nom [100], const string & src1, const string & src2, const string & img);

/**
@brief getLongueur : renvoie la longueur du nombre
@return unsigned int la longueur du nombre
@param unsigned int nombre correspond au nombre dont on veut connaitre la longueur
**/
	unsigned int getLongueur(const unsigned int nombre);
	
/**
@brief placer_image : place l'image sur le renderer
@param Jeu jeu correspond au jeu
@param SDL_Surface * surface correspond à l'image à afficher
@param Position postion correspond à la position de l'objet à afficher
**/
	void placer_image (const Jeu & jeu, SDL_Surface * surface, const Position &position);

/**
@brief placer_image : place l'image sur le renderer
@param SDL_Surface * surface correspond à l'image à afficher
@param unsigned int x correspond à la position horizontale sur l'ecran (0 à 100)%
@param unsigned int y correspond à la position verticale sur l'ecran (0 à 100)%
@param unsigned int largeur correspond à la largeur sur l'ecran
@param unsigned int hauteur correspond à la hauteur sur l'ecran
**/
	void placer_image (SDL_Surface * surface, const unsigned int x, const unsigned int y, const unsigned int largeur, const unsigned int hauteur);
	
/**
@brief afficherJeu: affiche la partie
@param Jeu correspond au jeu à afficher
**/
	void afficherPartie(const Jeu & jeu);
	
/**
@brief afficherPersonnage: affiche le personnage
@param Jeu correspond au jeu à afficher
**/
	void afficherPersonnage(const Jeu & jeu);

/**
@brief afficherMenu: affiche le Menu principal du jeu
@param char bouton le bouton sur lequel se trouve la souris
**/
	void afficherMenu(const char bouton);
	
/**
@brief afficherFond: affiche le fond et les objets du jeu
@param Jeu correspond au jeu à afficher
**/
	void afficherFond (const Jeu & jeu);
	
/**
@brief afficherFin: affiche les statistiques de fin de partie
@param Jeu correspond au jeu à afficher
@param char bouton le bouton sur lequel se trouve la souris
**/	
	void afficherFin(const Jeu & jeu,const char bouton);
	
/**
@brief afficherStatistiques: affiche les statistiques de jeu
@param Jeu correspond au jeu à afficher
@param char bouton le bouton sur lequel se trouve la souris
**/	
	void afficherStatistiques(const Jeu & jeu,const char bouton);
	
/**
@brief afficherStatistiques: affiche les statistiques de jeu
@param Jeu correspond au jeu à afficher
@param char bouton [3] le bouton sur lequel se trouve la souris
**/	
	void afficherBoutique(const Jeu & jeu,const char bouton[3]);
	
public:
	const unsigned int TAILLEX=800; //!< definit la taille horizontale de la fenetre SDL
	const unsigned int TAILLEY=600; //!< definit la taille verticale de la fenetre SDL
/**
@brief Affichage_SDL : constructeur de la classe Affichage_SDL
@param Jeu jeu correspond au jeu
**/
	Affichage_SDL(const Jeu & jeu);
/**
@brief ~Affichage_SDL : destructeur de la classe Affichage_SDL
**/
	~Affichage_SDL();

/**
@brief afficher: affiche le jeu entier
@param Jeu correspond au jeu à afficher
@param char c[3] correspond aux évenements
**/
	void afficher(const Jeu & jeu, const char c[3]);	

};

#endif

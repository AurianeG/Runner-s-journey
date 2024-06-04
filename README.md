

Runner's Journey 
-------------------

## Auteurs
Nicolas GALLET p2101620 

Auriane GONINDARD p2101407



## Description
Le joueur doit déplacer le personnage verticalement ou horizontalement en appuyant sur certaines touches du clavier. Le décor se déplace automatiquement selon l’axe horizontal 
Le décor, les pièces, les bonus et les obstacles défilent et sont générés aléatoirement.
Lorsque le personnage touche un obstacle, la partie s'arrête et le joueur retourne au menu principal.
Durant la partie, le personnage peut récupérer des bonus (invincibilité, aimant et vitesse) qui prennent effet immédiatement lorqu'ils sont touchés et durent un certain temps.
La vitesse de défilement du fond augmente avec le temps.
Le nombre de pièces et de bonus ramassés sont comptabilisés pour le calcul du score.
Il est possible d'acheter des costumes pour le personnage ou des décors dans la boutique.
Les statistiques des parties jouées sont disponibles dans le menu Statistiques.


ImageExemple.png

![Image d'exemple](doc/ImageExemple.png "Image d'exemple").

#

## Execution
Jeu en mode console: ./bin/jeu_console

Jeu en mode SDL : ./bin/jeu_SDL

## Jouer (Version Graphique)

Sur le menu principal, vous pouvez cliquer sur 4 boutons:
Bouton Jouer:

    Lance une partie.
        Appuyez sur z, q, s ou d pour vous deplacer.
        Appuyez sur 0 ou b pour revenir au menu principal.

Bouton Boutique:

    Ouvre la boutique.
        Vous pouvez cliquer sur un personnage ou un décor pour l'acheter ou pour le selectionner si il est déja acheté.
        Appuyez sur le bouton Retour pour revenir au menu principal.

Bouton Statistiques:

    Affiche les statistiques des parties.
        Appuyez sur le bouton Retour pour revenir au menu principal.

Bouton Reinitialiser:

    Efface les statistiques des parties précedentes, remet le nombre de pièces à 0 et annule les achats faits dans la boutique.

Quitter le jeu:

    Appuyez sur la croix en haut à droite ou appuyez sur 0 ou b.

## Librairie necessaires
   SDL2/SDL.h


## Dossiers/Fichiers
makefile 

bin  _Contient tous les fichiers executables_

data _Contient toutes les images et les fichiers de données_

    data/textes/données
        Contient les données néccessaire au chargement du jeu

            costumes.txt
                Contient la liste des costumes du personnage et leur prix.
            
            décors.txt
                Contient la liste des décors et leur prix.
            
            duréeBonus.txt
                Contient la liste des bonus et leur durée.
            
            obstacles.txt
                Contient les dimensions des obstacles du terrain.
    
    data/textes/sauvegardes
        Contient les données sauvegardées sur le jeu

            jeu.txt
                Contient le nombre de pièces possédées, le numéro du costume et du décor sélectionnés 
                et la liste des costumes et décors accompagnés d'un 1 si ils sont achetés 0 sinon.
            
            statistiques.txt
                Contient les statistiques de toutes les parties précedentes.

doc _Contient tous les fichiers de documentation_
    
    diagramme.png
        capture d'ecran du diagramme des classes
    
    runner.doxy
        le fichier doxygen du jeu
 

include _Contient tous les fichiers .h_

    Affichage_SDL.h

    Affichage_console.h

    Article.h

    Jeu_console.h

    Jeu_SDL.h

    Jeu.h

    Lot_Objets.h

    Magasin.h

    Objet.h

    Obstacle.h

    Partie.h

    Personnage.h

    Position.h 

    Scores.h

    Statistique.h

    Terrain.h

    
obj  _Contient tous les fichiers .o_

src _Contient tous les fichiers .cpp_

    Affichage_SDL.cpp

    Affichage_console.cpp

    Article.cpp

    Jeu_console.cpp

    Jeu_SDL.cpp

    Jeu.cpp

    Lot_Objets.cpp

    Magasin.cpp

    Objet.cpp

    Obstacle.cpp

    Partie.cpp

    Personnage.cpp

    Position.cpp 

    Scores.cpp

    Statistique.cpp

    Terrain.cpp

    mainSDL.cpp

    mainConsole.cpp


DIRCPP=src/
DIRH=include/
DIRO=obj/
OBJ=$(DIRO)Lot_objets.o $(DIRO)Objet.o $(DIRO)Obstacle.o $(DIRO)Position.o $(DIRO)Personnage.o $(DIRO)Terrain.o $(DIRO)Statistiques.o $(DIRO)Scores.o $(DIRO)Partie.o $(DIRO)Magasin.o $(DIRO)Article.o $(DIRO)Jeu.o $(DIRO)Affichage_console.o $(DIRO)Affichage_SDL.o $(DIRO)Jeu_console.o $(DIRO)Jeu_SDL.o
CC=g++
FLAG= -ggdb -Wall
FLAGS= -ggdb -c -Wall
NOM1=./bin/jeu_console
NOM2=./bin/jeu_SDL

MAIN1=mainConsole
MAIN2=mainSDL
LIBS=-lSDL2


all: $(NOM1) $(NOM2)

$(NOM1): $(DIRO)$(MAIN1).o $(OBJ)
	$(CC) $(FLAG) $(DIRO)$(MAIN1).o $(OBJ) -o $(NOM1) $(LIBS)
	
$(NOM2): $(DIRO)$(MAIN2).o $(OBJ)
	$(CC) $(FLAG) $(DIRO)$(MAIN2).o $(OBJ) -o $(NOM2) $(LIBS)

$(DIRO)$(MAIN1).o: $(DIRCPP)$(MAIN1).cpp $(DIRH)Jeu_console.h
	$(CC) $(FLAGS) $(DIRCPP)$(MAIN1).cpp -o $(DIRO)$(MAIN1).o
	
$(DIRO)$(MAIN2).o: $(DIRCPP)$(MAIN2).cpp $(DIRH)Jeu_SDL.h
	$(CC) $(FLAGS) $(DIRCPP)$(MAIN2).cpp -o $(DIRO)$(MAIN2).o

$(DIRO)Position.o: $(DIRCPP)Position.cpp $(DIRH)Position.h
	$(CC) $(FLAGS) $(DIRCPP)Position.cpp -o $(DIRO)Position.o
	
$(DIRO)Personnage.o: $(DIRCPP)Personnage.cpp $(DIRH)Personnage.h $(DIRH)Position.h
	$(CC) $(FLAGS) $(DIRCPP)Personnage.cpp -o $(DIRO)Personnage.o

$(DIRO)Objet.o: $(DIRCPP)Objet.cpp $(DIRH)Objet.h $(DIRH)Position.h
	$(CC) $(FLAGS) $(DIRCPP)Objet.cpp -o $(DIRO)Objet.o
	
$(DIRO)Obstacle.o: $(DIRCPP)Obstacle.cpp $(DIRH)Obstacle.h
	$(CC) $(FLAGS) $(DIRCPP)Obstacle.cpp -o $(DIRO)Obstacle.o

$(DIRO)Lot_objets.o: $(DIRCPP)Lot_objets.cpp $(DIRH)Lot_objets.h $(DIRH)Objet.h $(DIRH)Obstacle.h
	$(CC) $(FLAGS) $(DIRCPP)Lot_objets.cpp -o $(DIRO)Lot_objets.o
	
$(DIRO)Terrain.o: $(DIRCPP)Terrain.cpp $(DIRH)Terrain.h
	$(CC) $(FLAGS) $(DIRCPP)Terrain.cpp -o $(DIRO)Terrain.o
	
$(DIRO)Scores.o: $(DIRCPP)Scores.cpp $(DIRH)Scores.h
	$(CC) $(FLAGS) $(DIRCPP)Scores.cpp -o $(DIRO)Scores.o

$(DIRO)Partie.o: $(DIRCPP)Partie.cpp $(DIRH)Partie.h $(DIRH)Personnage.h $(DIRH)Terrain.h $(DIRH)Lot_objets.h $(DIRH)Scores.h
	$(CC) $(FLAGS) $(DIRCPP)Partie.cpp -o $(DIRO)Partie.o
	
$(DIRO)Statistiques.o: $(DIRCPP)Statistiques.cpp $(DIRH)Statistiques.h $(DIRH)Scores.h
	$(CC) $(FLAGS) $(DIRCPP)Statistiques.cpp -o $(DIRO)Statistiques.o
	
$(DIRO)Article.o: $(DIRCPP)Article.cpp $(DIRH)Article.h
	$(CC) $(FLAGS) $(DIRCPP)Article.cpp -o $(DIRO)Article.o
	
$(DIRO)Magasin.o: $(DIRCPP)Magasin.cpp $(DIRH)Magasin.h $(DIRH)Article.h
	$(CC) $(FLAGS) $(DIRCPP)Magasin.cpp -o $(DIRO)Magasin.o
	
$(DIRO)Affichage_console.o: $(DIRCPP)Affichage_console.cpp $(DIRH)Affichage_console.h $(DIRH)Jeu.h
	$(CC) $(FLAGS) $(DIRCPP)Affichage_console.cpp -o $(DIRO)Affichage_console.o

$(DIRO)Affichage_SDL.o: $(DIRCPP)Affichage_SDL.cpp $(DIRH)Affichage_SDL.h $(DIRH)Jeu.h
	$(CC) $(FLAGS) $(DIRCPP)Affichage_SDL.cpp -o $(DIRO)Affichage_SDL.o
	
$(DIRO)Jeu.o: $(DIRCPP)Jeu.cpp $(DIRH)Jeu.h $(DIRH)Partie.h $(DIRH)Statistiques.h $(DIRH)Magasin.h
	$(CC) $(FLAGS) $(DIRCPP)Jeu.cpp -o $(DIRO)Jeu.o

$(DIRO)Jeu_console.o: $(DIRCPP)Jeu_console.cpp $(DIRH)Jeu_console.h $(DIRH)Affichage_console.h
	$(CC) $(FLAGS) $(DIRCPP)Jeu_console.cpp -o $(DIRO)Jeu_console.o

$(DIRO)Jeu_SDL.o: $(DIRCPP)Jeu_SDL.cpp $(DIRH)Jeu_SDL.h $(DIRH)Affichage_SDL.h
	$(CC) $(FLAGS) $(DIRCPP)Jeu_SDL.cpp -o $(DIRO)Jeu_SDL.o


clean:
	rm $(DIRO)*.o
	rm -r bin/*


veryclean: clean
	rm *.out

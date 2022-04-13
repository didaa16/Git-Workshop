prog: main.o perso.o
	gcc  main.o perso.o -o prog -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer -g
main.o:main.c
	gcc -c main.c -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer -g
perso.o:perso.c
	gcc -c perso.c -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer -g

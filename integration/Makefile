prog:perso.o Background.o main.o
	gcc perso.o Background.o main.o -o prog -lSDL -lSDL_image -lSDL_mixer 
main.o:main.c
	gcc -c main.c -g
Background.o:Background.c
	gcc -c Background.c -g
perso.o:perso.c
	gcc -c perso.c -g

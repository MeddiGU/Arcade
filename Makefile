##
## EPITECH PROJECT, 2024
## B-OOP-400-MAR-4-1-arcade-meddi.gueran
## File description:
## Makefile
##


flags = -W -Wall -Wextra -Werror

core:
	g++ -o arcade ./Core/*.cpp main.cpp

games:
	g++ -o arcade_snake.so ./Games/snake/snake.cpp -shared -fPIC && mv arcade_snake.so ./lib
	g++ -o arcade_pacman.so ./Games/pacman/pacman.cpp -shared -fPIC && mv arcade_pacman.so ./lib
	g++ -o arcade_menu.so ./Games/menu/menu.cpp -shared -fPIC && mv arcade_menu.so ./lib

graphicals:
	g++ -o arcade_ncurses.so ./Lib/lib_ncurses.cpp -shared -fPIC -lncurses && mv arcade_ncurses.so ./lib
	g++ -o arcade_sfml.so ./Lib/lib_sfml.cpp -shared -fPIC -lsfml-graphics -lsfml-window -lsfml-system && mv arcade_sfml.so ./lib
	g++ -o arcade_sdl2.so ./Lib/lib_sdl2.cpp -shared -fPIC -lSDL2 -lSDL2_image -lSDL2_ttf && mv arcade_sdl2.so ./lib

all: core games graphicals

clean:
	rm -f arcade
	rm -f ./lib/arcade_ncurses.so
	rm -f ./lib/arcade_sfml.so
	rm -f ./lib/arcade_sdl2.so
	rm -f ./lib/arcade_snake.so
	rm -f ./lib/arcade_pacman.so
	rm -f ./lib/arcade_menu.so

fclean:
	rm -f arcade
	rm -f ./lib/arcade_ncurses.so
	rm -f ./lib/arcade_sfml.so
	rm -f ./lib/arcade_sdl2.so
	rm -f ./lib/arcade_snake.so
	rm -f ./lib/arcade_pacman.so
	rm -f ./lib/arcade_menu.so

re: fclean all


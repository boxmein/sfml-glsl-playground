
SFML = src/sfml/
INCLUDE = -I$(SFML)include/ -L$(SFML)lib/
LINK = -lsfml-window -lsfml-main -lsfml-system -lsfml-graphics
NAME = glsl-runner.exe
FILES = src/Main.cpp

all:
	g++ -o build/$(NAME) $(INCLUDE) $(LINK) $(DEFINE) $(FILES)

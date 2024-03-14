all:
	g++ -I SDL/src/include -L SDL/src/lib -o main main.cpp  Game.cpp TextureManager.cpp Map.cpp GameObject.cpp  -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
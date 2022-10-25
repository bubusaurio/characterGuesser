all:
	g++ -I src/include -L src/lib -o main main.cpp -lsfml-graphics -lsfml-window -lsfml-system
	
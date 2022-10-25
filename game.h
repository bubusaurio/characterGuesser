#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <stdlib.h>


//Global Variables
int nodeInitCounter = 0;
int nodeCounter = 0;
int nodeId;
bool nodeDesicion;
bool shiftFlag = true;
int maxNodeCount = 2;
int nodeCount = 0;
int nodeLayer = 0;
int nodeInitLayer = 0;
std::vector<std::string> questionString{"Male", "Walter White", "Ariel"};
std::string defaultQuestion = "Is Your Character ";


//Game engine

class game{
  private:
    //Variables
    sf::Event gameEvent;
    sf::VideoMode videoMode;

    //Game logic
    bool mouseHeld;
    

    //Mouse Positions
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;


    //Private Function
    void initVariables();
    void initWindow();

  public:
    sf::RenderWindow* window;
    //Contructor/Destructor
    game(); 
    virtual ~game();

    //Node
    struct node;
    node *createNode(std::string);
    void insertNode(node *&, std::string);
    node *tree = NULL;
    void showIdRight(node *);
    void rightShift(node *, std::string);
    void leftShift(node *, std::string);
    void questionGenerator(node *&tree);
    void characterGenerator();
    void binaryTreeGenerator(node *&tree);
    void nodeGenerator(int, bool);

    //Functions
    void updateGame();
    void updateMousePositions();
    void pollEvent();
    void update();
    void render();
    const bool running() const;
};
#include "game.cpp"
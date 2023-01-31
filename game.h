#pragma once

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
int score = 0;
std::vector<std::string> questionString{"Male", "Walter White", "Ariel"};
std::string defaultQuestion = "Is Your Character ";




//Game engine

class game{
  private:

  public:
  
    //Node
    struct node;
    node *createNode(std::string);
    void insertNode(node *&, std::string);
    node *tree = NULL;
    void showIdRight(node *);
    void rightShift(node *, std::string);
    void leftShift(node *, std::string);
    void questionGenerator(node *&tree);
    void binaryTreeGenerator(node *&tree);
    void nodeGenerator(int, bool);
};
#include "game.cpp"
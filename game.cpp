#include "game.h"

//Node Struct
struct game::node{
    std::string idChar;
    bool decision;

    node *right;
    node *left;
};

//Node Creator
game::node *game::createNode(std::string id){
    game::node *newNode = new game::node();

    newNode->idChar = id;
    newNode->right = NULL;
    newNode->left = NULL;

    return newNode;
}

//Tree Desicion Making
void game::insertNode(node *&tree, std::string id){
    if(tree == NULL){ //If the tree is empty
        game::node *newNode = createNode(id);
        tree = newNode;
    }
    else{ //If the tree has nodes
        bool rootValue = nodeDesicion; //Root Value
        if(rootValue == false){ //If the answer is false then go to the left of the tree
            insertNode(tree->left, id);
        }

        if(rootValue == true){ //If the answer is true then go to the right of the tree
            insertNode(tree->right, id);
        }
    }
}

void game::rightShift(node *tree, std::string charName){
    if(shiftFlag){
        shiftFlag = false;
        rightShift(tree->right, charName);
    }
    insertNode(tree, charName);
    shiftFlag = true;
}

void game::leftShift(node *tree, std::string charName){
    if(shiftFlag){
        shiftFlag = false;
        leftShift(tree->left, charName);
    }
    insertNode(tree, charName);
    shiftFlag = true;
}

void game::nodeGenerator(int id, bool desicion){
    if(id != 0){
        nodeDesicion = desicion;
    }
    insertNode(tree, questionString[id]);
    nodeCount ++;
}

void game::binaryTreeGenerator(node *&tree){
    nodeGenerator(nodeCount, true);
    while(nodeCount<=maxNodeCount){
        nodeGenerator(nodeCount,true);
        nodeGenerator(nodeCount,false);
    }
}

void game::questionGenerator(node *&tree){
    node *aux = new node();
    bool answer;
    std::string character;
    std::string characterFeature;
    if(tree != NULL){
        std::cout<<"Is Your Character " << tree->idChar << "?\n";
        std::cin>>answer;

        if(!answer){
            score--;
            if(tree->left == NULL){
                std::cout<<"Did i guess your character?\n";
                std::cin>>answer;

                if(!answer){
                    std::cout<<"Tell me a feature of your character?\n";
                    std::cin>>characterFeature;
                    insertNode(tree->left, characterFeature);

                    aux = tree;
                    tree = tree->left;
                    tree->left = aux;

                    std::cout<<"Whos your character?\n";
                    std::cin>>character;
                    insertNode(tree->right, character);
                    return;
                }

                else{
                    std::cout<<"EAAASSSYYYY BOOOOYYYY\n";
                    score = 5;
                    return;
                }
            }
            else{
                questionGenerator(tree->left);
            }
        }

        else{
            score++;
            if(tree->right == NULL){
                std::cout<<"Did i guess your character?\n";
                std::cin>>answer;

                if(!answer){
                    std::cout<<"Tell me a feature of your character?\n";
                    std::cin>>characterFeature;
                    insertNode(tree->left, characterFeature);

                    aux = tree;
                    tree = tree->left;
                    tree->left = aux;

                    std::cout<<"Whos your character?\n";
                    std::cin>>character;
                    insertNode(tree->right, character);
                    return;
                }

                else{
                    std::cout<<"EAAASSSYYYY BOOOOYYYY\n";
                    return;
                }
            }
            else{
                questionGenerator(tree->right);
            } 
        }
    } 
}
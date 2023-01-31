#include "game.h"


int main(){
    //Init game engine
    game _game;
    bool flag = true;
    _game.binaryTreeGenerator(_game.tree);

    while(flag){
        _game.questionGenerator(_game.tree);

        std::cout<<"Wanna continue?\n";
        std::cin>>flag;

    }

    std::cout<<"End Game\n";

    return 0;
}
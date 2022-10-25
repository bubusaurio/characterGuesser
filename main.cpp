#include "game.h"


int main(){
    //Init game engine
    game _game;
    bool flag = true;
    _game.binaryTreeGenerator(_game.tree);

    //Test Binary tree
    // while(flag){
    //     _game.questionGenerator(_game.tree);

    //     std::cout<<"Wanna continue?\n";
    //     std::cin>>flag;

    // }

    std::cout<<"End Game\n";

    //Gameloop
    while(_game.running()){
        //EventPolling

        //Update
        _game.update();

        //Render
        _game.render();

        //Draw Window  

    }

    return 0;
}
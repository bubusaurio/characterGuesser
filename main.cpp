#include "game.h"


int main(){
    //Init game engine
    game _game;

    //Test Binary tree
    _game.binaryTreeGenerator(_game.tree);
    _game.questionGenerator(_game.tree);

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
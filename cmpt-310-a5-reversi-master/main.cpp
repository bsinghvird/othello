#include <iostream>
#include "reversiLogic/reversi.h"

using namespace std;


int main() {


    Reversi reversi = Reversi();
    reversi.introMessage();

    //default game mode against monte carlo AI
    reversi.startGame();

    //other game modes with different opponent types
//    reversi.twoPlayer();
//    reversi.playGameAgainstPositionalStrategyAI();
//    reversi.playGameAgainstHeuristicAI();
//    reversi.playGameAgainstRandomAI();

    //used for testing purposes
//    reversi.findNumPlayOuts();
//    reversi.heuristicVsMonteCarloMultiGameTest(10, 20);


    return 0;
}
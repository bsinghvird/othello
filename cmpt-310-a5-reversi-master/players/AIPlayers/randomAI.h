#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <random>
#include "../../reversiLogic/board.h"
#include "../../reversiLogic/gameLogic.h"

#pragma once

using namespace std;

class RandomAI
{
private:
    Tiles tile = Tiles::white;

public:


    RandomAI(Tiles playerTile)
    {
        tile = playerTile;
    }

    Tiles getTile() const {
        return tile;
    }

    string getMove(GameLogic board)
    {

        vector<vector<int>> indexes = board.findTileIndexes(Tiles::valid_move);

        srand(time(NULL));
        int randomIndex = rand()%indexes.size();
        vector<int> index = indexes[randomIndex];
        int row = index[0]+1;
        int col = index[1]+1;

        string move = to_string(row)  + to_string(col);

        return move;
    }

};
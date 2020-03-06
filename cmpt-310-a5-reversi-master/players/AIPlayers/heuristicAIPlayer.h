#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "../../reversiLogic/tiles.h"
#include "../../reversiLogic/gameLogic.h"

#pragma once

using namespace std;

class HeuristicAiPlayer
{
private:
    Tiles tile = Tiles::white;
public:

    HeuristicAiPlayer(Tiles playerTile)
    {
        tile = playerTile;
    }

    Tiles getTile() const {
        return tile;
    }

    string getMove(GameLogic board)
    {

        vector<vector<int>> indexes = board.findTileIndexes(Tiles::valid_move);
        vector<int> numTilesFlipped;

        //check if a corner move is available
        for(int i =0; i<indexes.size(); i++)
        {
            vector<int> currentIndex = indexes[i];


            int row = currentIndex[0];
            int col = currentIndex[1];

            if(row==0 && col == 0)
            {
                string move = to_string(row+1)  + to_string(col+1);

                return move;
            }
            else if(row==0 && col == 7)
            {
                string move = to_string(row+1)  + to_string(col+1);


                return move;
            }
            else if(row==7 && col == 0)
            {
                string move = to_string(row+1)  + to_string(col+1);


                return move;
            }
            else if(row==7 && col == 7)
            {
                string move = to_string(row+1)  + to_string(col+1);


                return move;
            }
        }

        for(int i =0; i < indexes.size(); i ++)
        {
            vector<int> currentIndex = indexes[i];
            GameLogic tempGame = GameLogic();
            tempGame.setBoard(board.getBoard());

            int row = currentIndex[0]+1;
            int col = currentIndex[1]+1;

            int tilesFlipped = findNumTilesFlipped(row,col,tempGame);
            numTilesFlipped.push_back(tilesFlipped);

        }

        int indexOfMove = findIndexOfMaxInt(numTilesFlipped);
        vector<int> pickedMove = indexes[indexOfMove];


        int row = pickedMove[0]+1;
        int col = pickedMove[1]+1;


        string move = to_string(row)  + to_string(col);


        return move;


    }

    int findNumTilesFlipped(int row, int col, GameLogic board)
    {
        string move = to_string(row)  + to_string(col);

        int numTilesFlipped = board.insertTile(move, tile);

        return numTilesFlipped;
    }

    int findIndexOfMaxInt(vector<int> tilesFlipped)
    {
        int indexMax =0;
        int max = tilesFlipped[0];

        for(int i=0; i<tilesFlipped.size(); i++)
        {
            if(tilesFlipped[i] > max)
            {
                max = tilesFlipped[i];
                indexMax = i;
            }
        }

        return indexMax;
    }

};
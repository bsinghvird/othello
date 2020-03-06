#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "../../reversiLogic/tiles.h"
#include "../../reversiLogic/gameLogic.h"

#pragma once

using namespace std;

class PositionalStrategyAIPlayer
{
private:
    Tiles tile = Tiles::white;
    vector<vector<int>> positionValues;

    //board positional values were taken from this presentation: http://play-othello.appspot.com/files/Othello.pdf
    void setUpBoardPositionValues()
    {
        vector<int> row1 = {100,-20,10,5,5,10,-20,100};
        vector<int> row2 = {-20,-50,-2,-2,-2,-2,-50,-20};
        vector<int> row3 ={10,-2,-1,-1,-1,-1,-2,5};
        vector<int> row4 ={5,-2,-1,-1,-1,-1,-2,5};
        vector<int> row5 ={5,-2,-1,-1,-1,-1,-2,5};
        vector<int> row6 ={10,-2,-1,-1,-1,-1,-2,5};
        vector<int> row7 ={-20,-50,-2,-2,-2,-2,-50,-20};
        vector<int> row8 ={100,-20,10,5,5,10,-20,100};

        positionValues.push_back(row1);
        positionValues.push_back(row2);
        positionValues.push_back(row3);
        positionValues.push_back(row4);
        positionValues.push_back(row5);
        positionValues.push_back(row6);
        positionValues.push_back(row7);
        positionValues.push_back(row8);
    }


public:

    explicit PositionalStrategyAIPlayer(Tiles playerTile)
    {
        tile = playerTile;
        setUpBoardPositionValues();
    }


    Tiles getTile() const {
        return tile;
    }

    string getMove(GameLogic board)
    {

        vector<vector<int>> indexes = board.findTileIndexes(Tiles::valid_move);
        vector<int> weights;


        for(int i =0; i < indexes.size(); i ++)
        {
            vector<int> currentIndex = indexes[i];
            GameLogic tempGame = GameLogic();
            tempGame.setBoard(board.getBoard());

            int row = currentIndex[0];
            int col = currentIndex[1];

            int weight = positionValues[row][col];
            weights.push_back(weight);


        }

        int indexOfMove = findIndexOfMaxInt(weights);
        vector<int> pickedMove = indexes[indexOfMove];


        int row = pickedMove[0]+1;
        int col = pickedMove[1]+1;


        string move = to_string(row)  + to_string(col);


        return move;


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
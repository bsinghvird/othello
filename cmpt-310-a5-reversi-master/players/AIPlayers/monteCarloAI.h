#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <afxres.h>
#include "../../reversiLogic/board.h"
#include "../../reversiLogic/gameLogic.h"
#include "randomAI.h"
#include <fstream>

#pragma once

using namespace std;

class MonteCarloAI
{
private:
    Tiles tile = Tiles::white;

public:

    MonteCarloAI(Tiles playerTile)
    {
        tile = playerTile;
    }

    Tiles getTile() const {
        return tile;
    }

    Tiles setEnemyTile()
    {
        Tiles enemyTile;
        if(tile==Tiles::black)
        {
            enemyTile = Tiles ::white;
        }

        else
        {
            enemyTile =Tiles ::black;
        }

        return enemyTile;
    }

    bool playOutAGame(GameLogic board, string move)
    {

        GameLogic tempGame = GameLogic();
        tempGame.setBoard(board.getBoard());
        Tiles enemyTile = setEnemyTile();
        tempGame.insertTile(move, tile);
        RandomAI tempRandomFriendlyPlayer = RandomAI(tile);
        RandomAI tempRandomEnemyPlayer = RandomAI(enemyTile);

        while (tempGame.getGameState() == GameState::inProgress)
        {
            bool tempRandomEnemySkipped = false;
            bool tempRandomFriendlySkipped = false;

            //black tile
            if(tempGame.getGameState()== GameState::inProgress)
            {
                int numMoves = tempGame.findValidMove(tempRandomEnemyPlayer.getTile(), tempRandomFriendlyPlayer.getTile());
                if(numMoves>0)
                {
                    string playerMove = tempRandomEnemyPlayer.getMove(tempGame);
                    tempGame.insertTile(playerMove, tempRandomEnemyPlayer.getTile());
                }

                else
                {
                    tempRandomEnemySkipped = true;
                }

            }

            //white tile
            if(tempGame.getGameState()== GameState::inProgress)
            {
                int numMoves = tempGame.findValidMove(tempRandomFriendlyPlayer.getTile(), tempRandomEnemyPlayer.getTile());

                if(numMoves>0)
                {

                    string computerMove = tempRandomFriendlyPlayer.getMove(tempGame);
                    tempGame.insertTile(computerMove, tempRandomFriendlyPlayer.getTile());
                }

                else
                {
                    tempRandomFriendlySkipped = true;
                }

            }

            if(tempRandomEnemySkipped&&tempRandomFriendlySkipped)
            {
                tempGame.findWinner();
            }

        }

        if(tempGame.getGameState()==GameState::tie||tempGame.getGameState()==GameState::whiteWins)
        {
            return true;
        }
        else
        {
            return false;
        }

    }

    int findIndexOfMaxInt(vector<int> winsOrTies)
    {
        int indexMax =0;
        int max = winsOrTies[0];

        for(int i=0; i<winsOrTies.size(); i++)
        {
            if(winsOrTies[i] > max)
            {
                max = winsOrTies[i];
                indexMax = i;
            }
        }

        return indexMax;
    }


    string getMove(GameLogic board, int numPlayouts)
    {

        cout << "Computer's turn" << endl;
        Tiles enemyTile = setEnemyTile();
        board.findValidMove(tile,enemyTile);
        vector<vector<int>> indexes = board.findTileIndexes(Tiles::valid_move);
        cout << "AI is computing next move" << endl;
        vector<int> winsOrTies;
        RandomAI blackTilePlayer = RandomAI(Tiles::black);
        RandomAI whiteTilePlayer = RandomAI(Tiles::white);


        //for every possible move that the computer can make
        for(int i = 0; i < indexes.size(); i++)
        {
            GameLogic tempGame = GameLogic();
            tempGame.setBoard(board.getBoard());
            vector<int>currentMove = indexes[i];
            int numWins = 0;

            int row = currentMove[0]+1;
            int col = currentMove[1]+1;
            string move = to_string(row)  + to_string(col);

            int startTime = time(0);

            //play out a game x times
            for(int j = 0; j < numPlayouts; j++)
            {
                if(playOutAGame(tempGame,move))
                {
                    numWins++;
                }

            }

            winsOrTies.push_back(numWins);
        }

        int indexMax = findIndexOfMaxInt(winsOrTies);
        vector<int> pickedMove = indexes[indexMax];

        int row = pickedMove[0]+1;
        int col = pickedMove[1]+1;

        string move = to_string(row)  + to_string(col);

        return move;
    }

};
#include <iostream>
#include <iomanip>
#include <vector>
#include "board.h"
#include "gameStates.h"

#pragma once

using namespace std;

class GameLogic: public Board
{
private:
    GameState gameState = GameState ::inProgress;

    void defaultBoard()
    {
        board[3][3] = Tiles ::white;
        board[4][4] = Tiles ::white;
        board[4][3] = Tiles ::black;
        board[3][4] = Tiles ::black;
    }

    void findVerticalMoves(Tiles friendlyTile,Tiles enemyTile,vector<vector<int>> indexes)
    {

        findAbove(friendlyTile, enemyTile, indexes);
        findBelow(friendlyTile, enemyTile, indexes);

    }

    void findAbove(Tiles friendlyTile,Tiles enemyTile,vector<vector<int>> indexes)
    {
        for(int i = 0; i < indexes.size(); i++)
        {
            vector<int> currentIndex = indexes[i];

            bool canPlace = false;
            for(int row = currentIndex[0]; row >=0;row--)
            {
                int col = currentIndex[1];

                if(board[row][col] == enemyTile)
                {
                    canPlace = true;
                }

                if(board[row][col] == friendlyTile)
                {
                    canPlace = false;
                }

                if(board[row][col] == Tiles::valid_move)
                {
                    break;
                }

                if(board[row][col]==Tiles::empty && !canPlace) {
                    break;

                }

                if(board[row][col]==Tiles::empty && canPlace) {
                    board[row][col] = Tiles::valid_move;
                    break;

                }

            }
        }
    }

    void findBelow(Tiles friendlyTile,Tiles enemyTile,vector<vector<int>> indexes)
    {
        for(int i = 0; i < indexes.size(); i++)
        {
            vector<int> currentIndex = indexes[i];

            bool canPlace = false;

            for(int row = currentIndex[0]; row <boardSize;row++)
            {
                int col = currentIndex[1];

                if(board[row][col] == enemyTile)
                {
                    canPlace = true;
                }

                if(board[row][col] == friendlyTile)
                {
                    canPlace = false;
                }

                if(board[row][col] == Tiles::valid_move)
                {
                    break;
                }


                if(board[row][col]==Tiles::empty && !canPlace) {
                    break;

                }

                if(board[row][col]==Tiles::empty && canPlace) {
                    board[row][col] = Tiles::valid_move;
                    break;

                }

            }
        }
    }

    void findHorizontalMoves(Tiles friendlyTile,Tiles enemyTile,vector<vector<int>> indexes)
    {
        findLeft(friendlyTile, enemyTile, indexes);
        findRight(friendlyTile, enemyTile, indexes);


    }

    void findLeft(Tiles friendlyTile,Tiles enemyTile,vector<vector<int>> indexes)
    {
        for (int i = 0; i < indexes.size(); i++) {
            vector<int> currentIndex = indexes[i];

            bool canPlace = false;
            for (int col = currentIndex[1]; col >= 0; col--) {

                int row = currentIndex[0];

                if (board[row][col] == enemyTile) {
                    canPlace = true;
                    continue;
                }

                if (board[row][col] == friendlyTile) {
                    canPlace = false;
                }

                if(board[row][col] == Tiles::valid_move)
                {
                    break;
                }

                if(board[row][col]==Tiles::empty && !canPlace) {
                    break;

                }
                if (board[row][col] == Tiles::empty && canPlace) {
                    board[row][col] = Tiles::valid_move;
                    break;

                }

            }

        }
    }

    void findRight(Tiles friendlyTile,Tiles enemyTile,vector<vector<int>> indexes)
    {

        for (int i = 0; i < indexes.size(); i++) {
            vector<int> currentIndex = indexes[i];

            bool canPlace = false;
            for (int col = currentIndex[1]; col < boardSize; col++) {

                int row = currentIndex[0];

                if (board[row][col] == enemyTile) {
                    canPlace = true;
                    continue;
                }

                if (board[row][col] == friendlyTile) {
                    canPlace = false;
                }
                if(board[row][col] == Tiles::valid_move)
                {
                    break;
                }


                if(board[row][col]==Tiles::empty && !canPlace) {
                    break;

                }
                if (board[row][col] == Tiles::empty && canPlace) {
                    board[row][col] = Tiles::valid_move;
                    break;

                }

            }

        }
    }

    void findDiagonalMoves(Tiles friendlyTile,Tiles enemyTile,vector<vector<int>> indexes)
    {
        findUpperLeft(friendlyTile, enemyTile, indexes);
        findUpperRight(friendlyTile, enemyTile, indexes);
        findLowerRight(friendlyTile, enemyTile, indexes);
        findLowerLeft(friendlyTile, enemyTile, indexes);


    }

    void findUpperLeft(Tiles friendlyTile,Tiles enemyTile,vector<vector<int>> indexes)
    {
        for (int i = 0; i < indexes.size(); i++) {
            vector<int> currentIndex = indexes[i];

            bool canPlace = false;
            int row = currentIndex[0];
            for (int col = currentIndex[1]; col >= 0; col--) {

                if(row>=0)
                {
                    if (board[row][col] == enemyTile) {
                        canPlace = true;
                    }

                    if (board[row][col] == friendlyTile) {
                        canPlace = false;
                    }
                    if(board[row][col] == Tiles::valid_move)
                    {
                        break;
                    }


                    if(board[row][col]==Tiles::empty && !canPlace) {
                        break;

                    }
                    if (board[row][col] == Tiles::empty && canPlace) {
                        board[row][col] = Tiles::valid_move;
                        break;

                    }


                }

                row--;

            }

        }
    }

    void findUpperRight(Tiles friendlyTile,Tiles enemyTile,vector<vector<int>> indexes)
    {
        for (int i = 0; i < indexes.size(); i++) {
            vector<int> currentIndex = indexes[i];

            bool canPlace = false;
            int row = currentIndex[0];
            for (int col = currentIndex[1]; col < boardSize; col++) {

                if(row>=0)
                {
                    if (board[row][col] == enemyTile) {
                        canPlace = true;
                    }

                    if (board[row][col] == friendlyTile) {
                        canPlace = false;
                    }

                    if(board[row][col] == Tiles::valid_move)
                    {
                        break;
                    }

                    if(board[row][col]==Tiles::empty && !canPlace) {
                        break;

                    }
                    if (board[row][col] == Tiles::empty && canPlace) {
                        board[row][col] = Tiles::valid_move;
                        break;

                    }


                }

                row--;

            }

        }
    }

    void findLowerRight(Tiles friendlyTile,Tiles enemyTile,vector<vector<int>> indexes)
    {
        for (int i = 0; i < indexes.size(); i++) {
            vector<int> currentIndex = indexes[i];

            bool canPlace = false;
            int row = currentIndex[0];
            for (int col = currentIndex[1]; col <boardSize ; col++) {

                if(row<boardSize)
                {
                    if (board[row][col] == enemyTile) {
                        canPlace = true;
                    }

                    if (board[row][col] == friendlyTile) {
                        canPlace = false;
                    }
                    if(board[row][col] == Tiles::valid_move)
                    {
                        break;
                    }

                    if(board[row][col]==Tiles::empty && !canPlace) {
                        break;

                    }
                    if (board[row][col] == Tiles::empty && canPlace) {
                        board[row][col] = Tiles::valid_move;
                        break;

                    }

                }

                row++;

            }

        }
    }

    void findLowerLeft(Tiles friendlyTile,Tiles enemyTile,vector<vector<int>> indexes)
    {
        for (int i = 0; i < indexes.size(); i++) {
            vector<int> currentIndex = indexes[i];

            bool canPlace = false;
            int row = currentIndex[0];
            for (int col = currentIndex[1]; col >=0 ; col--) {

                if(row<boardSize)
                {
                    if (board[row][col] == enemyTile) {
                        canPlace = true;
                    }

                    if (board[row][col] == friendlyTile) {
                        canPlace = false;
                    }
                    if(board[row][col] == Tiles::valid_move)
                    {
                        break;
                    }


                    if(board[row][col]==Tiles::empty && !canPlace) {
                        break;

                    }
                    if (board[row][col] == Tiles::empty && canPlace) {
                        board[row][col] = Tiles::valid_move;
                        break;

                    }

                }

                row++;

            }

        }
    }

    int flipAllTiles(Tiles tile, int row, int col)
    {
        Tiles enemyTile;
        int numTilesFlipped = 0;
        int numVerticalTilesFlipped = 0;
        int numHorizontalTilesFlipped = 0;
        int numDiagonalTilesFlipped = 0;
        if(tile==Tiles::black)
        {
            enemyTile = Tiles ::white;

        }

        else
        {
            enemyTile =Tiles ::black;
        }

        clearBoard();
        numVerticalTilesFlipped = flipVerticalTiles(tile, enemyTile, row, col);
        numHorizontalTilesFlipped = flipHorizontalTiles(tile, enemyTile, row, col);
        numDiagonalTilesFlipped = flipDiagonalTiles(tile, enemyTile, row, col);

        numTilesFlipped = numVerticalTilesFlipped + numHorizontalTilesFlipped + numDiagonalTilesFlipped;
        return numTilesFlipped;

    }

    void flipTiles(vector<vector<int>> tiles, Tiles tile)
    {
        for(int i = 0 ; i < tiles.size(); i++)
        {
            vector<int> currentTile = tiles[i];
            int row = currentTile[0];
            int col = currentTile[1];

            board[row][col] = tile;
        }
    }

    int flipVerticalTiles(Tiles friendlyTile, Tiles enemyTile, int row, int col)
    {
        int numVerticalTilesFlipped = 0;
        int numAboveTilesFlipped = 0;
        int numBelowTilesFlipped = 0;

        numAboveTilesFlipped = flipAbove(friendlyTile, enemyTile, row,col);
        numBelowTilesFlipped = flipBelow(friendlyTile, enemyTile, row, col);

        numVerticalTilesFlipped = numAboveTilesFlipped+numBelowTilesFlipped;

        return numVerticalTilesFlipped;

    }

    int flipHorizontalTiles(Tiles friendlyTile, Tiles enemyTile, int row, int col)
    {
        int numHorizontalTilesFlipped = 0;
        int numLeftTilesFlipped = 0;
        int numRightTilesFlipped = 0;

        numLeftTilesFlipped = flipLeft(friendlyTile, enemyTile, row, col);
        numRightTilesFlipped = flipRight(friendlyTile, enemyTile, row, col);

        numHorizontalTilesFlipped = numLeftTilesFlipped+numRightTilesFlipped;

        return numHorizontalTilesFlipped;
    }

    int flipDiagonalTiles(Tiles friendlyTile, Tiles enemyTile, int row, int col)
    {
        int numDiagonalTilesFlipped = 0;
        int numTopLeftTilesFlipped = 0;
        int numTopRightTilesFlipped = 0;
        int numBottomLeftTilesFlipped = 0;
        int numBottomRightTilesFlipped = 0;

        numTopLeftTilesFlipped = flipTopLeft(friendlyTile, enemyTile, row, col);
        numTopRightTilesFlipped = flipTopRight(friendlyTile, enemyTile, row, col);
        numBottomLeftTilesFlipped = flipBottomLeft(friendlyTile, enemyTile, row, col);
        numBottomRightTilesFlipped = flipBottomRight(friendlyTile, enemyTile, row, col);

        numDiagonalTilesFlipped = numTopLeftTilesFlipped + numTopRightTilesFlipped
                                  + numBottomLeftTilesFlipped + numBottomRightTilesFlipped;

        return numDiagonalTilesFlipped;
    }

    int flipAbove(Tiles friendlyTile, Tiles enemyTile, int row, int col)
    {
        vector<vector<int>> tilesToFLip;
        bool canFlip = false;

        for(int i = row-1; i >=0; i--)
        {
            if(board[i][col]== Tiles::empty||board[i][col]== Tiles::valid_move)
            {
                break;
            }

            if(board[i][col] == enemyTile)
            {
                vector<int> tileToFlip = {i,col};
                tilesToFLip.push_back(tileToFlip);
            }

            if(board[i][col] == friendlyTile)
            {
                canFlip=true;
                break;
            }

        }

        if(canFlip)
        {
            flipTiles(tilesToFLip, friendlyTile);
        }
        else
        {
            return 0;
        }

        return tilesToFLip.size();
    }

    int flipBelow(Tiles friendlyTile, Tiles enemyTile,int row, int col)
    {
        vector<vector<int>> tilesToFLip;
        bool canFlip = false;

        for(int i = row+1; i <board.size(); i++)
        {
            if(board[i][col]== Tiles::empty)
            {
                break;
            }

            if(board[i][col] == enemyTile)
            {
                vector<int> tileToFlip = {i,col};
                tilesToFLip.push_back(tileToFlip);
            }

            if(board[i][col] == friendlyTile)
            {
                canFlip=true;
                break;
            }

        }

        if(canFlip)
        {
            flipTiles(tilesToFLip, friendlyTile);
        }
        else
        {
            return 0;
        }

        return tilesToFLip.size();
    }

    int flipLeft(Tiles friendlyTile, Tiles enemyTile,int row, int col)
    {
        vector<vector<int>> tilesToFLip;
        bool canFlip = false;

        for(int i = col-1; i >=0; i--)
        {
            if(board[row][i]== Tiles::empty)
            {
                break;
            }

            if(board[row][i] == enemyTile)
            {
                vector<int> tileToFlip = {row,i};
                tilesToFLip.push_back(tileToFlip);
            }

            if(board[row][i] == friendlyTile)
            {
                canFlip=true;
                break;
            }

        }

        if(canFlip)
        {
            flipTiles(tilesToFLip, friendlyTile);
        }

        else
        {
            return 0;
        }

        return tilesToFLip.size();
    }

    int flipRight(Tiles friendlyTile, Tiles enemyTile,int row, int col)
    {
        vector<vector<int>> tilesToFLip;
        bool canFlip = false;

        for(int i = col+1; i <boardSize; i++)
        {
            if(board[row][i]== Tiles::empty||board[row][i]== Tiles::valid_move)
            {
                break;
            }

            if(board[row][i] == enemyTile)
            {
                vector<int> tileToFlip = {row,i};
                tilesToFLip.push_back(tileToFlip);
            }

            if(board[row][i] == friendlyTile)
            {
                canFlip=true;
                break;
            }

        }

        if(canFlip)
        {
            flipTiles(tilesToFLip, friendlyTile);
        }

        else
        {
            return 0;
        }

        return tilesToFLip.size();
    }

    int flipTopLeft(Tiles friendlyTile, Tiles enemyTile,int row, int col)
    {
        row--;
        vector<vector<int>> tilesToFLip;
        bool canFlip = false;
        for(int i = col-1; i >=0; i--)
        {
            if(row>=0)
            {

                if(board[row][i]== Tiles::empty)
                {
                    break;
                }

                if(board[row][i] == enemyTile)
                {
                    vector<int> tileToFlip = {row,i};
                    tilesToFLip.push_back(tileToFlip);
                }

                if(board[row][i] == friendlyTile)
                {
                    canFlip=true;
                    break;
                }
            }

            row--;
        }

        if(canFlip)
        {
            flipTiles(tilesToFLip, friendlyTile);
        }

        else
        {
            return 0;
        }

        return tilesToFLip.size();
    }

    int flipTopRight(Tiles friendlyTile, Tiles enemyTile,int row, int col)
    {
        row--;
        vector<vector<int>> tilesToFLip;
        bool canFlip = false;
        for(int i = col+1; i <boardSize; i++)
        {

            if(row>=0)
            {
                if(board[row][i]== Tiles::empty)
                {
                    break;
                }

                if(board[row][i] == friendlyTile)
                {
                    canFlip=true;
                    break;
                }

                if(board[row][i] == enemyTile)
                {
                    vector<int> tileToFlip = {row,i};
                    tilesToFLip.push_back(tileToFlip);
                }


            }
            row--;
        }

        if(canFlip)
        {
            flipTiles(tilesToFLip, friendlyTile);
        }

        else
        {
            return 0;
        }

        return tilesToFLip.size();
    }

    int flipBottomRight(Tiles friendlyTile, Tiles enemyTile,int row, int col)
    {
        row++;
        vector<vector<int>> tilesToFLip;
        bool canFlip = false;
        for(int i = col+1; i <boardSize; i++)
        {
            if(row<boardSize)
            {

                if(board[row][i]== Tiles::empty)
                {
                    break;
                }

                if(board[row][i] == enemyTile)
                {
                    vector<int> tileToFlip = {row,i};
                    tilesToFLip.push_back(tileToFlip);
                }

                if(board[row][i] == friendlyTile)
                {
                    canFlip=true;
                    break;
                }
            }
            row++;
        }

        if(canFlip)
        {
            flipTiles(tilesToFLip, friendlyTile);
        }

        else
        {
            return 0;
        }

        return tilesToFLip.size();
    }

    int flipBottomLeft(Tiles friendlyTile, Tiles enemyTile,int row, int col)
    {
        row++;
        vector<vector<int>> tilesToFLip;
        bool canFlip = false;
        for(int i = col-1; i >=0; i--)
        {
            if(row<boardSize) {
                if (board[row][i] == Tiles::empty) {
                    break;
                }

                if (board[row][i] == enemyTile) {
                    vector<int> tileToFlip = {row, i};
                    tilesToFLip.push_back(tileToFlip);
                }

                if (board[row][i] == friendlyTile) {
                    canFlip = true;
                    break;
                }
            }

            row++;
        }

        if(canFlip)
        {
            flipTiles(tilesToFLip, friendlyTile);
        }

        else
        {
            return 0;
        }

        return tilesToFLip.size();
    }

public:

    GameState getGameState() const
    {
        return gameState;
    }

    GameLogic ()
    {
        defaultBoard();
    }

    void setGameState(GameState gameState)
    {
        GameLogic::gameState = gameState;
    }

    int insertTile(string move, Tiles tile)
    {
        int charConversion = 49;

        int row = (int)move[0]-charConversion;
        int col = (int)move[1]-charConversion;


        board[row][col] = tile;

        int numTilesFLipped = flipAllTiles(tile, row, col);

        return numTilesFLipped;
    }

    int findValidMove(Tiles tile, Tiles enemyTile)
    {
        vector<vector<int>> indexes = findTileIndexes(tile);

        findVerticalMoves(tile,enemyTile, indexes);
        findHorizontalMoves(tile,enemyTile, indexes);
        findDiagonalMoves(tile,enemyTile, indexes);

        int numPossibleMoves = findTileIndexes(Tiles::valid_move).size();

        return numPossibleMoves;
    }

    vector<vector<int>> findTileIndexes(Tiles tile)
    {
        vector<vector<int>> indexes;

        for(int i = 0; i < boardSize; i++)
        {
            for(int j = 0; j<boardSize; j++)
            {
                if(board[i][j]==tile)
                {
                    vector<int> index = {i,j};
                    indexes.push_back(index);
                }
            }
        }

        return indexes;
    }

    void findWinner()
    {
        int numWhiteTiles = 0;
        int numBlackTiles = 0;
        for(int i =0; i < boardSize; i++)
        {
            vector<Tiles> currentRow = board[i];
            for(int j = 0; j <boardSize; j++)
            {
                Tiles currentTile = currentRow[j];

                if (currentTile ==Tiles::white)
                {
                    numWhiteTiles++;
                }
                else if (currentTile == Tiles::black)
                {
                    numBlackTiles++;
                }

            }
        }

        if(numWhiteTiles>numBlackTiles)
        {
            setGameState(GameState ::whiteWins);

        }

        else if(numBlackTiles>numWhiteTiles)
        {
            setGameState(GameState ::blackWins);

        }

        else if(numBlackTiles == numWhiteTiles)
        {
            setGameState(GameState::tie);
        }


    }

    GameState printWinner()
    {
        if(gameState==GameState::blackWins)
        {
            cout << "Black Wins!" << endl;

        }

        if(gameState==GameState::whiteWins)
        {
            cout << "White Wins!" << endl;

        }

        if(gameState == GameState::tie)
        {
            cout << "Tie!" << endl;

        }

        return gameState;
    }

    void printBoard()
    {
        string topRow = "# 1 2 3 4 5 6 7 8 #";
        cout << topRow << endl;
        for(int i =0; i < boardSize; i++)
        {
            vector<Tiles> currentRow = board[i];
            cout << i+1 << " ";

            for(int j =0; j < boardSize; j++)
            {
                cout << char(currentRow[j]) << " ";
            }

            cout << i+1 << endl;
        }

        cout << topRow << endl << endl;

        printCurrentScore();
    }

    void printCurrentScore()
    {
        int numBlackTiles = 0;
        int numWhiteTiles = 0;

        for(int i =0; i < boardSize; i++)
        {
            for(int j = 0; j < boardSize; j++)
            {
                if(board[i][j]==Tiles::black)
                {
                    numBlackTiles++;
                }

                else if(board[i][j]==Tiles::white)
                {
                    numWhiteTiles++;
                }

            }
        }

        cout << "Current Score" << endl;
        cout << "Black Tiles: " << numBlackTiles << endl;
        cout << "White Tiles: " << numWhiteTiles << endl << endl;

    }

};
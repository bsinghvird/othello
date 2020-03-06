#include <iostream>
#include <iomanip>
#include <vector>
#include "tiles.h"
#pragma once

using namespace std;
class Board
{

protected:
    vector<vector<Tiles>> board;
    int boardSize = 8;

public:

    Board()
    {

        vector<Tiles> emptyRow = vector<Tiles>(boardSize, Tiles::empty);
        for(int i = 0; i < boardSize; i++)
        {
            board.push_back(emptyRow);
        }

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

    }

    void manualPlace(int row, int col, Tiles tile)
    {
        board[row-1][col-1] = tile;
    }

    vector<vector<Tiles>> getBoard()
    {
        return board;
    }

    void setBoard(vector<vector<Tiles>> newBoard)
    {
        board = newBoard;
    }

    void clearBoard()
    {
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board.size(); j++)
            {
                if (board[i][j] == Tiles ::valid_move)
                {
                    board[i][j] =Tiles ::empty;
                }
            }
        }
    }

};

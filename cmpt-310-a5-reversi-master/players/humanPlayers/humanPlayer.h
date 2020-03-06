#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

#pragma once

using namespace std;

class HumanPlayer
{
private:
    Tiles tile = Tiles::black;
public:

    HumanPlayer(Tiles playerTile)
    {
        tile = playerTile;
    }

    Tiles getTile() const {
        return tile;
    }

    string getMove(GameLogic board)
    {
        bool validMove = false;
        string move;

        while(!validMove)
        {
            cout << "Enter your move";
            cin >> move;

            if (checkValidMove(move, board.getBoard())) {
                validMove = true;

            }
        }

        cout << endl;
        return move;
    }

    bool checkValidMove(string move, vector<vector<Tiles>> board)
    {
        int moveLength = 2;
        int conversion = 48;
        string errorMessage = "Invalid input, please try again. ";

        if( move.length() !=moveLength)
        {
            cout << errorMessage << endl;
            return false;
        }

        if(!isdigit(move[0])||!isdigit(move[1]))
        {
            cout << errorMessage << "Please enter integers only" << endl;
            return false;
        }

        int row = (int)move[0]-conversion;
        int col = (int)move[1]-conversion;

        if(!checkIfOnBoard(row, col))
        {
            cout << errorMessage << "Please enter values between 1 and 8" << endl;
            return false;
        }


        if(!checkValidSpot(row-1, col-1, board))
        {
            cout << errorMessage << "Valid moves are marked with a ^" << endl;
            return false;
        }


        return true;
    }

    bool checkValidSpot(int row, int col, vector<vector<Tiles>> board)
    {

        if(board[row][col] != Tiles::valid_move)
        {
            return false;
        }

        return true;
    }

    bool checkIfOnBoard(int row, int col)
    {
        int boardSize = 8;
        if(row>boardSize||row<1)
        {
            return false;
        }

        if(col>boardSize||col<1)
        {
            return false;
        }

        return true;
    }

};
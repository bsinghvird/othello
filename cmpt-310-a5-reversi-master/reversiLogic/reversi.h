#include <iostream>
#include <iomanip>
#include "board.h"
#include "gameLogic.h"
#include "../players/humanPlayers/humanPlayer.h"
#include "../players/AIPlayers/monteCarloAI.h"
#include "../players/AIPlayers/positionalStrategyAIPlayer.h"
#include "../players/AIPlayers/heuristicAIPlayer.h"
#include <fstream>

#pragma once


using namespace std;

ofstream myFile2;

class Reversi
{

private:

    string getWinner(GameState gameState)
    {
        if(gameState==GameState::blackWins)
        {
            return "Black";

        }

        if(gameState==GameState::whiteWins)
        {
            return "White";

        }

        if(gameState == GameState::tie)
        {
            return "Tie";

        }


    }

    float findAverages(vector<int> time)
    {
        float average = 0;

        for(int i =0; i<time.size(); i++)
        {
            average+=time[i];
        }

        average = average/time.size();

        return average;



    }

public:

    vector<int> times = {};

    Reversi()
    {
        myFile2.open("report.csv");
    }

    void introMessage()
    {
        cout << endl;
        cout << "Welcome to the (nearly) unbeatable reversi game! Try your best to beat the computer." << endl;
        cout << "The goal of the game is to have more tiles than your opponent at the end of the game" << endl;
        cout << "Valid moves are marked with a \"^\" on the board" << endl;
        cout << "You are the black tile player in this game, and your opponent is the white tile player" << endl;
        cout << "Enter your moves as \"row\"\"col\" " << endl;
        cout << "For example if I wanted to place a tile at row 3 column 4, I would type in 34. No space, commas or quotations." << endl;
        cout << "Failing to format a response as so will result in the program asking for your move again." << endl;
        cout << "Good Luck and have fun!" << endl << endl;

    }

    bool askIfWantsToPlayAgain()
    {
        char response;
        bool answered = false;
        bool playAgain = false;

        while(!answered)
        {
            cout << "Do you want to play again? (y/n)" << endl;
            cin >> response;

            if(response== 'y')
            {
                playAgain = true;
                answered = true;
            }

            else if(response=='n')
            {
                playAgain = false;
                answered = true;
            }

            else
            {
                cout << "Please answer with \"y\" or \"n\"" << endl;
            }


        }

        return playAgain;



    }

    //human player games
    void twoPlayer()
    {
        GameLogic board = GameLogic();
        HumanPlayer blackTilePlayer = HumanPlayer(Tiles::black);
        HumanPlayer whiteTilePlayer = HumanPlayer(Tiles::white);
        board.printBoard();
        cout << endl;

        while(board.getGameState()== GameState::inProgress)
        {
            bool playerSkipped = false;
            bool computerSkipped = false;

            if(board.getGameState()== GameState::inProgress)
            {
                board.clearBoard();
                int numMoves = board.findValidMove(blackTilePlayer.getTile(), whiteTilePlayer.getTile());
                if(numMoves>0)
                {
                    board.printBoard();
                    string playerMove = blackTilePlayer.getMove(board);
                    board.insertTile(playerMove, blackTilePlayer.getTile());
                }

                else
                {
                    playerSkipped = true;
                }

                board.clearBoard();
                board.printBoard();
                cout << endl;
            }

            if(board.getGameState()== GameState::inProgress)
            {
                board.clearBoard();
                int numMoves = board.findValidMove(whiteTilePlayer.getTile(), blackTilePlayer.getTile());

                if(numMoves>0)
                {
                    board.printBoard();
                    string computerMove = whiteTilePlayer.getMove(board);
                    board.insertTile(computerMove, whiteTilePlayer.getTile());
                }

                else
                {
                    computerSkipped = true;
                }

                board.clearBoard();
                board.printBoard();
                cout << endl;
            }


            if(playerSkipped&&computerSkipped)
            {
                board.findWinner();
            }

        }
    }

    void playGameAgainstRandomAI()
    {
        GameLogic board = GameLogic();
        HumanPlayer player = HumanPlayer(Tiles::black);
        RandomAI computer = RandomAI(Tiles::white);
        board.printBoard();
        cout << endl;

        while(board.getGameState()== GameState::inProgress)
        {
            bool playerSkipped = false;
            bool computerSkipped = false;

            if(board.getGameState()== GameState::inProgress)
            {
                int numMoves = board.findValidMove(player.getTile(), computer.getTile());
                if(numMoves>0)
                {
                    board.printBoard();
                    string playerMove = player.getMove(board);
                    board.insertTile(playerMove, player.getTile());
                }

                else
                {
                    playerSkipped = true;
                }

                board.printBoard();
                cout << endl;
            }

            if(board.getGameState()== GameState::inProgress)
            {
                int numMoves = board.findValidMove(computer.getTile(), player.getTile());

                if(numMoves>0)
                {
                    string computerMove = computer.getMove(board);
                    cout << "computer placed a tile at " << computerMove[0] << " " << computerMove[1] << endl;
                    board.insertTile(computerMove, computer.getTile());
                }

                else
                {
                    computerSkipped = true;
                }

                cout << endl;
            }


            if(playerSkipped&&computerSkipped)
            {
                board.findWinner();
            }

        }
    }

    void playGameAgainstHeuristicAI()
    {
        GameLogic board = GameLogic();
        HumanPlayer player = HumanPlayer(Tiles::black);
        HeuristicAiPlayer computer = HeuristicAiPlayer(Tiles::white);
        board.printBoard();

        cout << endl;

        while(board.getGameState()== GameState::inProgress)
        {
            bool playerSkipped = false;
            bool computerSkipped = false;

            if(board.getGameState()== GameState::inProgress)
            {
                int numMoves = board.findValidMove(player.getTile(), computer.getTile());
                if(numMoves>0)
                {
                    board.printBoard();
                    string playerMove = player.getMove(board);
                    board.insertTile(playerMove, player.getTile());
                }

                else
                {
                    playerSkipped = true;
                }

                board.printBoard();
                cout << endl;
            }

            if(board.getGameState()== GameState::inProgress)
            {

                int numMoves = board.findValidMove(computer.getTile(), player.getTile());

                if(numMoves>0)
                {
                    board.printBoard();
                    string computerMove = computer.getMove(board);
                    cout << "computer placed a tile at " << computerMove[0] << " " << computerMove[1] << endl;
                    board.insertTile(computerMove, computer.getTile());
                }

                else
                {
                    computerSkipped = true;
                }

                cout << endl;
            }


            if(playerSkipped&&computerSkipped)
            {
                board.findWinner();
                board.printWinner();
            }

        }
    }

    void playGameAgainstPositionalStrategyAI()
    {
        GameLogic board = GameLogic();
        HumanPlayer player = HumanPlayer(Tiles::black);
        PositionalStrategyAIPlayer computer = PositionalStrategyAIPlayer(Tiles::white);
        board.printBoard();

        cout << endl;

        while(board.getGameState()== GameState::inProgress)
        {
            bool playerSkipped = false;
            bool computerSkipped = false;

            if(board.getGameState()== GameState::inProgress)
            {
                int numMoves = board.findValidMove(player.getTile(), computer.getTile());
                if(numMoves>0)
                {
                    board.printBoard();
                    string playerMove = player.getMove(board);
                    board.insertTile(playerMove, player.getTile());
                }

                else
                {
                    playerSkipped = true;
                }

                board.printBoard();
                cout << endl;
            }

            if(board.getGameState()== GameState::inProgress)
            {

                int numMoves = board.findValidMove(computer.getTile(), player.getTile());

                if(numMoves>0)
                {
                    board.printBoard();
                    string computerMove = computer.getMove(board);
                    cout << "computer placed a tile at " << computerMove[0] << " " << computerMove[1] << endl;
                    board.insertTile(computerMove, computer.getTile());
                }

                else
                {
                    computerSkipped = true;
                }

                cout << endl;
            }


            if(playerSkipped&&computerSkipped)
            {
                board.findWinner();
                board.printWinner();
            }

        }
    }

    void playGameAgainstMonteCarloAI(int numPlayouts)
    {
        GameLogic board = GameLogic();
        HumanPlayer player = HumanPlayer(Tiles::black);
        MonteCarloAI computer = MonteCarloAI(Tiles::white);

        cout << endl;

        while(board.getGameState()== GameState::inProgress)
        {
            bool playerSkipped = false;
            bool computerSkipped = false;

            if(board.getGameState()== GameState::inProgress)
            {
                int numMoves = board.findValidMove(player.getTile(), computer.getTile());
                if(numMoves>0)
                {
                    board.printBoard();
                    string playerMove = player.getMove(board);
                    board.insertTile(playerMove, player.getTile());
                }

                else
                {
                    playerSkipped = true;
                }

                board.findValidMove(computer.getTile(), player.getTile());
                board.printBoard();
            }

            if(board.getGameState()== GameState::inProgress)
            {

                int numMoves = board.findValidMove(computer.getTile(), player.getTile());

                if(numMoves>0)
                {
                    string computerMove = computer.getMove(board, numPlayouts);
                    cout << "computer placed a tile at " << computerMove[0] << " " << computerMove[1] << endl;
                    board.insertTile(computerMove, computer.getTile());
                }

                else
                {
                    computerSkipped = true;
                }

                cout << endl;
            }


            if(playerSkipped&&computerSkipped)
            {
                board.findWinner();
                board.printWinner();
            }

        }
    }

    //AI Games
    GameState positionalStrategyVsMonteCarlo(int numPlayouts)
    {
        GameLogic board = GameLogic();
        PositionalStrategyAIPlayer weightBoardAiPlayer = PositionalStrategyAIPlayer(Tiles::black);
        MonteCarloAI monteCarloAI = MonteCarloAI(Tiles::white);
        vector<int> times;
        vector<int> monteTimes;
        board.printBoard();

        cout << endl;

        while(board.getGameState()== GameState::inProgress)
        {
            bool playerSkipped = false;
            bool computerSkipped = false;

            if(board.getGameState()== GameState::inProgress)
            {
                int numMoves = board.findValidMove(weightBoardAiPlayer.getTile(), monteCarloAI.getTile());
                if(numMoves>0)
                {
                    board.printBoard();
                    int startTime = time(0);
                    string playerMove = weightBoardAiPlayer.getMove(board);
                    int finishTime = time(0)-startTime;
                    times.push_back(finishTime);
                    board.insertTile(playerMove, weightBoardAiPlayer.getTile());


                }

                else
                {
                    playerSkipped = true;
                }

                board.printBoard();
                cout << endl;
            }

            if(board.getGameState()== GameState::inProgress)
            {

                int numMoves = board.findValidMove(monteCarloAI.getTile(), weightBoardAiPlayer.getTile());

                if(numMoves>0)
                {
                    board.printBoard();
                    int startTime = time(0);
                    string computerMove = monteCarloAI.getMove(board, numPlayouts);
                    int finishTime = time(0)-startTime;
                    monteTimes.push_back(finishTime);
                    cout << "computer placed a tile at " << computerMove[0] << " " << computerMove[1] << endl;
                    board.insertTile(computerMove, monteCarloAI.getTile());
                }

                else
                {
                    computerSkipped = true;
                }

                cout << endl;
            }


            if(playerSkipped&&computerSkipped)
            {
                board.findWinner();
                findAverages(times);
                findAverages(monteTimes);
                return board.printWinner();
            }

        }
    }

    GameState heuristicVsMonteCarlo(int numPlayouts)
    {
        GameLogic board = GameLogic();
        HeuristicAiPlayer heuristicAI = HeuristicAiPlayer(Tiles::black);
        MonteCarloAI monteCarloAI = MonteCarloAI(Tiles::white);
        board.printBoard();
        vector<int> monteTimes;

        cout << endl;

        while(board.getGameState()== GameState::inProgress)
        {
            bool playerSkipped = false;
            bool computerSkipped = false;

            if(board.getGameState()== GameState::inProgress)
            {
                int numMoves = board.findValidMove(heuristicAI.getTile(), monteCarloAI.getTile());
                if(numMoves>0)
                {
                    board.printBoard();
                    string playerMove = heuristicAI.getMove(board);
                    board.insertTile(playerMove, heuristicAI.getTile());
                }

                else
                {
                    playerSkipped = true;
                }

                board.printBoard();
                cout << endl;
            }

            if(board.getGameState()== GameState::inProgress)
            {

                int numMoves = board.findValidMove(monteCarloAI.getTile(), heuristicAI.getTile());

                if(numMoves>0)
                {

                    board.printBoard();
                    int startTime = time(0);
                    string computerMove = monteCarloAI.getMove(board, numPlayouts);
                    int finishTime = time(0)-startTime;
                    monteTimes.push_back(finishTime);
                    cout << "finish time = " << finishTime << endl;
                    times.push_back(finishTime);
                    cout << "computer placed a tile at " << computerMove[0] << " " << computerMove[1] << endl;
                    board.insertTile(computerMove, monteCarloAI.getTile());
                }

                else
                {
                    computerSkipped = true;
                }

                cout << endl;
            }


            if(playerSkipped&&computerSkipped)
            {
                board.findWinner();
                return board.printWinner();
            }

        }
    }

    //test functions
    void heuristicVsMonteCarloMultiGameTest(int numGames, int numPlayouts)
    {
        myFile2 << "Number of playouts, Number of wins and ties, Games Played, average time" << endl;
        int maxPlayouts = 300;
        int games =0;

        while(numPlayouts<=maxPlayouts) {

            int numWins = 0;
            times = {};
            myFile2<< numPlayouts << ",";
            for (int i = 0; i < numGames; i++) {
                GameState gs = heuristicVsMonteCarlo(numPlayouts);
                string winner = getWinner(gs);
                if(winner == "White" || winner =="Tie")
                {
                    numWins++;
                }

            }

            float average = findAverages(times);
            myFile2 << numWins << "," << numGames << "," << average << endl;


            numPlayouts+=20;
        }

    }

    void findNumPlayOuts()
    {
        int gamesToWin = 10;
        int gamesWon = 0;
        int numPlayOuts = 50;
        int currentGame = 1;
        int increaseBy = 50;

        bool passed = false;

        while(!passed)
        {
            cout << currentGame << endl;
            cout << "numplayouts = " << numPlayOuts << endl;
            GameState winner = heuristicVsMonteCarlo(numPlayOuts);

            if(winner == GameState::tie || winner == GameState::whiteWins)
            {
                currentGame++;
                gamesWon++;
            }

            if(gamesWon==gamesToWin)
            {
                passed = true;
            }

            if(winner==GameState::blackWins)
            {
                cout << "lost " << endl;
                currentGame = 1;
                gamesWon = 0;
                numPlayOuts+=increaseBy;
            }

            myFile2 << endl;


        }

        cout << "num play outs = " << numPlayOuts << endl;
    }

    //default game
    void startGame()
    {
        bool playing = true;
        int numPlayouts = 200;

        while(playing)
        {
            playGameAgainstMonteCarloAI(numPlayouts);
            playing = askIfWantsToPlayAgain();
        }
    }

};
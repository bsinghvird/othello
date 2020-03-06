cmake_minimum_required(VERSION 3.6)
project(cmpt310A5)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp reversiLogic/board.h reversiLogic/tiles.h players/humanPlayers/humanPlayer.h reversiLogic/gameLogic.h players/AIPlayers/randomAI.h reversiLogic/gameStates.h players/AIPlayers/monteCarloAI.h players/AIPlayers/heuristicAIPlayer.h players/AIPlayers/positionalStrategyAIPlayer.h reversiLogic/reversi.h)
add_executable(cmpt310A5 ${SOURCE_FILES})
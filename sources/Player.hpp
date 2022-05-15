
#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include "Game.hpp"
using namespace std;
namespace coup
{
/*
here is aclass for the player
the player have acounter toplaying than 
 count the coins to win
and have agame that she have acounter toplaying than
here is aheader
*/
    class Player
    {
    protected:
        Game &game;
        string _Name;
        int _coins = 0;
        OPERATION lastoper;
        int player_index;
        Player *lastOperPlayer;
        int x=0;
        int operations=0;
        double rewerr=0;
        string str;

    public:
        Player(Game &game, string playerName) : game(game), _Name(playerName)
        {
            player_index = game.numOfPlayers();
            game.setPlayerName(player_index, _Name);
            game.setPlayerTurn(player_index, player_index);
            game.setNumOfPlayers(game.numOfPlayers() + 1);

            if (game.Running() || game.numOfPlayers() > 6)
            {
                throw invalid_argument("Invalid ");
            }
        };
        void setCoins(int coins);
        void upateOperation(OPERATION oper);
        OPERATION getLastOper();
        int getPlayerIndex() const;
        void setLastOperPlayer(Player &otherPlayer);
        Player &getLastPlayer();

        const int tenC = 10;
        const int sevenC = 7;
        const int threeC = 3;
       
        int coins() const;
        void income();
        void foreign_aid();
        virtual void coup(Player &otherPlayer);
        virtual string role() { return ""; }

         void setCharAt( int page,  int x,  int y, char c);
        char charAt( int page,  int x,  int y) const;
        void updateBound(int start_x, int start_y, int size_x, int size_y);
        
        
      
        
    };
}
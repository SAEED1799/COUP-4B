
#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include "Game.hpp"
#include "Player.hpp"
using namespace std;
/*
here is aclass of captain
that have abiger of the groupingand have amo\any
coins
*/
namespace coup
{

    class Captain : public Player
    {
        private:
         int x=0;
        int operations=0;
        double rewerr=0;
        string str;

    public:
        Captain(Game &game, string playerName) : Player(game, playerName) {}
        string role() override;
        void steal(Player &otherPlayer);
        static void block(Player &otherPlayer);
    };

}
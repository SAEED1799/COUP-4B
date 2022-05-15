
#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include "Player.hpp"
using namespace std;
namespace coup
{

    class Contessa : public Player
    {
    private:
        int x=0;
        int operations=0;
        double rewerr=0;
        string str;


    public:
        Contessa(Game &game, string playerName) : Player(game, playerName) {}
        string role() override;
        void block(Player &otherPlayer); 
    };

}

#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

/*this is aclass of game
they have afunction that help to build agame
in this class we well update and set players
that we have with vector players
*/
namespace coup
{

    struct plr
    {
        string name;
        bool isCouped = false;
        int turn;
        int plrIndex;
    };

    enum OPERATION
    {
        INCOME,
        FOREIGN_AID,
        COUP,
        ROLE,
        BLOCK,
        TRANSFER,
        ASSASSIN,
        TAX,
        STEAL,
        STEAL1,

    };

    class Game
    {
    protected:
        
        int _numOfPlayers = 0;
        bool running = false;
        map<int, plr> _Map;
        int x=0;
        int operations=0;
        double rewerr=0;
        string str;

    public:
        Game(){};
     
        
        string turn();
        string winner();
        vector<string> players();

       
        int numOfPlayers() const;
        int getTurn() const;
        bool Running() const;
        void setNumOfPlayers(int num);
        void setPlayerTurn(int playerIndex, int turn);
        void setPlayerName(int playerIndex, string const &name);
        void setCopued(int playerIndex, bool copued);
        bool isCopued(int playerIndex);
        int playerTurn(int playerIndex);
        void resetTurns();
        void updateTurns();
        void setRunning(bool rn);
        void setTurn(int currPlayerIndex);
         void show(int pages) const;
    };

}
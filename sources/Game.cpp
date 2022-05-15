
#include "Game.hpp"
namespace coup
{
/*this is aclass of game
they have afunction that help to build agame
in this class we well update and set players
that we have with vector players
*/
    vector<string> Game::players()
    {
        vector<string> _players;
        for (int i = 0; i < _Map.size(); i++)
        {
            if (!_Map[i].isCouped)
            {
                _players.push_back(_Map[i].name);
            }
        }
        return _players;
    }

     
    
   
    void Game::resetTurns()
    {
        int t = 0;
        if (x == _numOfPlayers)
        {
            setTurn(0);
        }

        for (int i = 0; i < _Map.size(); i++)
        {
            if (!_Map[i].isCouped)
            {
                setPlayerTurn(i, t);
                t++;
            }
        }
    }

    string Game::winner()
    {

        if (_Map.size() == 1 || running)
        {
            throw "Game Still Running!!";
        }

        return players()[0];
    }

    string Game::turn()
    {
        return _Map[x].name;
    }
    void Game::setTurn(int currPlayerIndex)
    {
        this->x = currPlayerIndex;
    }

    int Game::numOfPlayers() const
    {
        return _numOfPlayers;
    }
    void Game::setNumOfPlayers(int num)
    {
        _numOfPlayers = num;
    }
    int Game::getTurn() const
    {
        return x;
    }
    void Game::updateTurns()
    {

        if (_numOfPlayers == 1 && !running)
        {
            throw " big then 1";
        }
        if (_numOfPlayers > 1)
        {
            running = true;
        }
        if (x == _numOfPlayers - 1)
        {
            setTurn(0);
        }
        else
        {
            setTurn(x + 1);
        }
    }


    void Game::setPlayerName(int playerIndex, string const &name)
    {
        _Map[playerIndex].name = name;
    }

    void Game::setCopued(int playerIndex, bool copued)
    {
        _Map[playerIndex].isCouped = copued;
    }
    void Game::setPlayerTurn(int playerIndex, int turn)
    {
        _Map[playerIndex].turn = turn;
    }
    int Game::playerTurn(int playerIndex)
    {
        return _Map[playerIndex].turn;
    }
    bool Game::isCopued(int playerIndex)
    {
        return _Map[playerIndex].isCouped;
    }
    void Game::setRunning(bool rn)
    {
        running = rn;
    }

    bool Game::Running() const
    {
        return running;
    }

}
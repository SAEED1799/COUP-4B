
#include "Player.hpp"
#include "Game.hpp"


/*
here is aclass for the player
the player have acounter toplaying than 
 count the coins to win
and have agame that she have acounter toplaying than
here is aclass 
*/
namespace coup
{

    void Player::income()
    {
        int plrT = game.playerTurn(player_index);
        bool b = (plrT == game.getTurn() && !game.isCopued(player_index));
        if (coins() >= tenC || !b)
        {

            throw invalid_argument("Invalid ");
        }
        _coins++;
        game.updateTurns();
        upateOperation(INCOME);
    }

    void Player::foreign_aid()
    {
        int plrT = game.playerTurn(player_index);
        bool b = (plrT == game.getTurn() && !game.isCopued(player_index));
        if (coins() >= tenC || !b)
        {
            throw invalid_argument("Invalid");
        }

        _coins += 2;
        game.updateTurns();
        upateOperation(FOREIGN_AID);
    }

    void Player::coup(Player &otherPlayer)
    {

        int plrT = game.playerTurn(player_index);
        int otherplrT = game.playerTurn(otherPlayer.getPlayerIndex());

        bool b = (plrT == game.getTurn() && !game.isCopued(otherPlayer.getPlayerIndex()));
        if (coins() < sevenC || !b)
        {
            throw invalid_argument("Invalid ");
        }

        game.setCopued(otherPlayer.getPlayerIndex(), true);
        game.setNumOfPlayers(game.numOfPlayers() - 1);
        setCoins(coins() - sevenC);

        if (game.getTurn() < otherplrT)
        {
            game.updateTurns();
        }
        game.resetTurns();
        if (game.numOfPlayers() == 1)
        {
            game.setRunning(false);
        }
        this->setLastOperPlayer(otherPlayer);

        upateOperation(COUP);
    }

    int Player::coins() const
    {
        return _coins;
    }
    void Player::setCoins(int coins)
    {
        _coins = coins;
    }

    void Player::upateOperation(OPERATION oper)
    {
        lastoper = oper;
    }

    OPERATION Player::getLastOper()
    {
        return lastoper;
    }

    int Player::getPlayerIndex() const
    {
        return player_index;
    }

    void Player::setLastOperPlayer(Player &otherPlayer)
    {
        lastOperPlayer = &otherPlayer;
    }

    Player &Player::getLastPlayer()
    {
        return *lastOperPlayer;
    }

}


#include "Contessa.hpp"
namespace coup
{

    string Contessa::role()
    {
        return "Contessa";
    }

    void Contessa::block(Player &otherPlayer)
    {

        if (otherPlayer.getLastOper() == ASSASSIN)
        {
            int otherplrT = game.playerTurn(otherPlayer.getLastPlayer().getPlayerIndex());
            game.setCopued(otherPlayer.getLastPlayer().getPlayerIndex(), false);
            game.setNumOfPlayers(game.numOfPlayers() + 1);
            game.resetTurns();
            if (game.getTurn() > otherplrT)
            {
                game.updateTurns();
            }

            return;
        }

        throw invalid_argument("Invalid ");
    }

}
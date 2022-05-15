
#include "Duke.hpp"
namespace coup
{

    string Duke::role()
    {
        return "Duke";
    }

    void Duke::tax()
    {
        int plrT = game.playerTurn(player_index);
        bool b = (plrT == game.getTurn() && !game.isCopued(player_index));
        if (coins() >= tenC || !b)
        {
            throw invalid_argument("Invalid ");
        }

        _coins += threeC;
        game.updateTurns();
        upateOperation(TAX);
    }

    void Duke::block(Player &otherPlayer)
    {
        if (otherPlayer.getLastOper() == FOREIGN_AID)
        {

            int c = otherPlayer.coins();
            otherPlayer.setCoins(c - 2);
            return;
        }

        throw invalid_argument("Invalid ");
    }
}
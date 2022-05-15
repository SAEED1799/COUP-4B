
#include "Ambassador.hpp"
namespace coup
{

    void Ambassador::transfer(Player &player1, Player &player2)
    {
        int plrT = game.playerTurn(player_index);
        bool b = (plrT == game.getTurn() && !game.isCopued(player_index));
        if (coins() >= tenC || player1.coins() < 1 || !b)
        {
            throw invalid_argument("Invalid");
        }
        game.updateTurns();
        player1.setCoins(player1.coins() - 1);
        player2.setCoins(player2.coins() + 1);
        upateOperation(TRANSFER);
    }

    void Ambassador::block(Player &otherPlayer)
    {

        if (otherPlayer.getLastOper() != STEAL && otherPlayer.getLastOper() != STEAL1)
        {
            throw invalid_argument("Invalid");
        }
        if (otherPlayer.getLastOper() == STEAL)
        {
            int a = otherPlayer.getLastPlayer().coins();
            int b = otherPlayer.coins();
            otherPlayer.setCoins(b - 2);
            otherPlayer.getLastPlayer().setCoins(a + 2);
        }
        else if (otherPlayer.getLastOper() == STEAL1)
        {
            int a = otherPlayer.getLastPlayer().coins();
            int b = otherPlayer.coins();
            otherPlayer.setCoins(b - 1);
            otherPlayer.getLastPlayer().setCoins(a + 1);
        }
    }
    string Ambassador::role()
    {
        return "Ambassador";
    }
}

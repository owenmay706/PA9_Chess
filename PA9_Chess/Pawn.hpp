#pragma once
#include "Piece.hpp"

class Pawn : public Piece
{
public:
    Pawn(int t, int r, int c) : Piece(t, r, c) {}

    char getSymbol() const override
    {
        return (team == 0) ? 'P' : 'p';
    }

    int getMoves(int movesR[], int movesC[]) override
    {
        int count = 0;

        // White moves up (-1), Black moves down (+1)
        int dir;
        if (team == 0)
            dir = -1;
        else
            dir = 1;

        // forward move (1 square)
        if (inBounds(row + dir, col))
        {
            movesR[count] = row + dir;
            movesC[count] = col;
            count++;
        }

        // capture diagonally left
        if (inBounds(row + dir, col - 1))
        {
            movesR[count] = row + dir;
            movesC[count] = col - 1;
            count++;
        }

        // capture diagonally right
        if (inBounds(row + dir, col + 1))
        {
            movesR[count] = row + dir;
            movesC[count] = col + 1;
            count++;
        }

        return count;
    }
};
#pragma once
#include "Piece.hpp"

class Rook : public Piece
{
public:
    Rook(int t, int r, int c) : Piece(t, r, c) {}

    char getSymbol() const override
    {
        return (team == 0) ? 'R' : 'r';
    }

    int getMoves(int movesR[], int movesC[]) override
    {
        int count = 0;

        // up
        for (int r = row - 1; r >= 0; r--)
        {
            movesR[count] = r;
            movesC[count] = col;
            count++;
        }

        // down
        for (int r = row + 1; r < 8; r++)
        {
            movesR[count] = r;
            movesC[count] = col;
            count++;
        }

        // left
        for (int c = col - 1; c >= 0; c--)
        {
            movesR[count] = row;
            movesC[count] = c;
            count++;
        }

        // right
        for (int c = col + 1; c < 8; c++)
        {
            movesR[count] = row;
            movesC[count] = c;
            count++;
        }

        return count;
    }
};
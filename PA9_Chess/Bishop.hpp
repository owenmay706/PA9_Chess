#pragma once
#include "Piece.hpp"

class Bishop : public Piece
{
public:
    Bishop(int t, int r, int c) : Piece(t, r, c) {}

    char getSymbol() const override
    {
        return (team == 0) ? 'B' : 'b';
    }

    int getMoves(int movesR[], int movesC[]) override
    {
        int count = 0;

        // up-left
        for (int r = row - 1, c = col - 1; inBounds(r, c); r--, c--)
        {
            movesR[count] = r;
            movesC[count] = c;
            count++;
        }

        // up-right
        for (int r = row - 1, c = col + 1; inBounds(r, c); r--, c++)
        {
            movesR[count] = r;
            movesC[count] = c;
            count++;
        }

        // down-left
        for (int r = row + 1, c = col - 1; inBounds(r, c); r++, c--)
        {
            movesR[count] = r;
            movesC[count] = c;
            count++;
        }

        // down-right
        for (int r = row + 1, c = col + 1; inBounds(r, c); r++, c++)
        {
            movesR[count] = r;
            movesC[count] = c;
            count++;
        }

        return count;
    }
};
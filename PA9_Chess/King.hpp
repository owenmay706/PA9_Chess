#pragma once
#include "Piece.hpp"

class King : public Piece
{
public:
    King(int t, int r, int c) : Piece(t, r, c) {}

    char getSymbol() const override
    {
        return (team == 0) ? 'K' : 'k';
    }

    int getMoves(int movesR[], int movesC[]) override
    {
        int count = 0;

        if (inBounds(row - 1, col))
        {
            movesR[count] = row - 1;
            movesC[count] = col;
            count++;
        }

        if (inBounds(row + 1, col))
        {
            movesR[count] = row + 1;
            movesC[count] = col;
            count++;
        }

        if (inBounds(row, col - 1))
        {
            movesR[count] = row;
            movesC[count] = col - 1;
            count++;
        }

        if (inBounds(row, col + 1))
        {
            movesR[count] = row;
            movesC[count] = col + 1;
            count++;
        }

        if (inBounds(row - 1, col - 1))
        {
            movesR[count] = row - 1;
            movesC[count] = col - 1;
            count++;
        }

        if (inBounds(row - 1, col + 1))
        {
            movesR[count] = row - 1;
            movesC[count] = col + 1;
            count++;
        }

        if (inBounds(row + 1, col - 1))
        {
            movesR[count] = row + 1;
            movesC[count] = col - 1;
            count++;
        }

        if (inBounds(row + 1, col + 1))
        {
            movesR[count] = row + 1;
            movesC[count] = col + 1;
            count++;
        }

        return count;
    }
};
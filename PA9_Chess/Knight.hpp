#pragma once
#include "Piece.hpp"

class Knight : public Piece
{
public:
    Knight(int t, int r, int c) : Piece(t, r, c) {}

    char getSymbol() const override
    {
        return (team == 0) ? 'N' : 'n';
    }

    int getMoves(int movesR[], int movesC[]) override
    {
        int count = 0;

        if (inBounds(row + 2, col + 1))
        {
            movesR[count] = row + 2;
            movesC[count] = col + 1;
            count++;
        }

        if (inBounds(row + 2, col - 1))
        {
            movesR[count] = row + 2;
            movesC[count] = col - 1;
            count++;
        }

        if (inBounds(row - 2, col + 1))
        {
            movesR[count] = row - 2;
            movesC[count] = col + 1;
            count++;
        }

        if (inBounds(row - 2, col - 1))
        {
            movesR[count] = row - 2;
            movesC[count] = col - 1;
            count++;
        }

        if (inBounds(row + 1, col + 2))
        {
            movesR[count] = row + 1;
            movesC[count] = col + 2;
            count++;
        }

        if (inBounds(row + 1, col - 2))
        {
            movesR[count] = row + 1;
            movesC[count] = col - 2;
            count++;
        }

        if (inBounds(row - 1, col + 2))
        {
            movesR[count] = row - 1;
            movesC[count] = col + 2;
            count++;
        }

        if (inBounds(row - 1, col - 2))
        {
            movesR[count] = row - 1;
            movesC[count] = col - 2;
            count++;
        }

        return count;
    }
};
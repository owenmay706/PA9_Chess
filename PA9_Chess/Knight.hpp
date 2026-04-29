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

    int getMoves(int movesR[], int movesC[], Piece* board[8][8]) override {
        int count = 0;
        int jumps[8][2] = { {2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2} };
        for (auto& j : jumps) {
            int r = row + j[0], c = col + j[1];
            if (inBounds(r, c) && (board[r][c] == nullptr || board[r][c]->getTeam() != team)) {
                movesR[count] = r; movesC[count] = c; count++;
            }
        }
        return count;
    }
};
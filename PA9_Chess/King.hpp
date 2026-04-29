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
    int getMoves(int movesR[], int movesC[], Piece* board[8][8]) override {
        int count = 0;
        int dirs[8][2] = { {-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1} };
        for (auto& d : dirs) {
            int r = row + d[0], c = col + d[1];
            if (inBounds(r, c) && (board[r][c] == nullptr || board[r][c]->getTeam() != team)) {
                movesR[count] = r; movesC[count] = c; count++;
            }
        }
        return count;
    }
};
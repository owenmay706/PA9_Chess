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

    int getMoves(int movesR[], int movesC[], Piece* board[8][8]) override {
        int count = 0;
        // up-left
        for (int r = row - 1, c = col - 1; inBounds(r, c); r--, c--) {
            movesR[count] = r; movesC[count] = c; count++;
            if (board[r][c] != nullptr) break;
        }
        // up-right
        for (int r = row - 1, c = col + 1; inBounds(r, c); r--, c++) {
            movesR[count] = r; movesC[count] = c; count++;
            if (board[r][c] != nullptr) break;
        }
        // down-left
        for (int r = row + 1, c = col - 1; inBounds(r, c); r++, c--) {
            movesR[count] = r; movesC[count] = c; count++;
            if (board[r][c] != nullptr) break;
        }
        // down-right
        for (int r = row + 1, c = col + 1; inBounds(r, c); r++, c++) {
            movesR[count] = r; movesC[count] = c; count++;
            if (board[r][c] != nullptr) break;
        }
        return count;
    }
};
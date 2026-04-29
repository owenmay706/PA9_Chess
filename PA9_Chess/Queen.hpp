#pragma once
#include "Piece.hpp"

class Queen : public Piece
{
public:
    Queen(int t, int r, int c) : Piece(t, r, c) {}

    char getSymbol() const override
    {
        return (team == 0) ? 'Q' : 'q';
    }

    int getMoves(int movesR[], int movesC[], Piece* board[8][8]) override {
        int count = 0;
        // Rook directions
        for (int r = row - 1; r >= 0; r--) {
            movesR[count] = r; movesC[count] = col; count++;
            if (board[r][col] != nullptr) break;
        }
        for (int r = row + 1; r < 8; r++) {
            movesR[count] = r; movesC[count] = col; count++;
            if (board[r][col] != nullptr) break;
        }
        for (int c = col - 1; c >= 0; c--) {
            movesR[count] = row; movesC[count] = c; count++;
            if (board[row][c] != nullptr) break;
        }
        for (int c = col + 1; c < 8; c++) {
            movesR[count] = row; movesC[count] = c; count++;
            if (board[row][c] != nullptr) break;
        }
        // Bishop directions
        for (int r = row - 1, c = col - 1; inBounds(r, c); r--, c--) {
            movesR[count] = r; movesC[count] = c; count++;
            if (board[r][c] != nullptr) break;
        }
        for (int r = row - 1, c = col + 1; inBounds(r, c); r--, c++) {
            movesR[count] = r; movesC[count] = c; count++;
            if (board[r][c] != nullptr) break;
        }
        for (int r = row + 1, c = col - 1; inBounds(r, c); r++, c--) {
            movesR[count] = r; movesC[count] = c; count++;
            if (board[r][c] != nullptr) break;
        }
        for (int r = row + 1, c = col + 1; inBounds(r, c); r++, c++) {
            movesR[count] = r; movesC[count] = c; count++;
            if (board[r][c] != nullptr) break;
        }
        return count;
    }
};
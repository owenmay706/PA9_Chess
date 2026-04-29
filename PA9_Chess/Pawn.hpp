#pragma once
#include "Piece.hpp"

class Pawn : public Piece {
private:
    bool hasMoved = false;
public:
    Pawn(int t, int r, int c) : Piece(t, r, c) {}

    void setMoved() { hasMoved = true; }

    char getSymbol() const override {
        return (team == 0) ? 'P' : 'p';
    }

    int getMoves(int movesR[], int movesC[], Piece* board[8][8]) override {
        int count = 0;
        int dir = (team == 0) ? -1 : 1;

        // forward 1 — only if empty
        if (inBounds(row + dir, col) && board[row + dir][col] == nullptr) {
            movesR[count] = row + dir; movesC[count] = col; count++;

            // forward 2 — only on first move and if both squares empty
            if (!hasMoved && inBounds(row + dir * 2, col) && board[row + dir * 2][col] == nullptr) {
                movesR[count] = row + dir * 2; movesC[count] = col; count++;
            }
        }

        // captures — only if enemy is there
        if (inBounds(row + dir, col - 1) && board[row + dir][col - 1] != nullptr && board[row + dir][col - 1]->getTeam() != team) {
            movesR[count] = row + dir; movesC[count] = col - 1; count++;
        }
        if (inBounds(row + dir, col + 1) && board[row + dir][col + 1] != nullptr && board[row + dir][col + 1]->getTeam() != team) {
            movesR[count] = row + dir; movesC[count] = col + 1; count++;
        }
        return count;
    }
};
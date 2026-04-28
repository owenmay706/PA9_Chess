#pragma once
#include <iostream>

class Piece
{
protected:
    int team;   // 0 = White, 1 = Black
    int row;
    int col;

public:
    int movesR[30];
    int movesC[30];
    Piece(int t, int r, int c)
    {
        team = t;
        row = r;
        col = c;
    }

    virtual ~Piece() {}

    int getTeam() const { return team; }
    int getRow() const { return row; }
    int getCol() const { return col; }

    void setPosition(int r, int c)
    {
        row = r;
        col = c;
    }

    bool inBounds(int r, int c)
    {
        return (r >= 0 && r < 8 && c >= 0 && c < 8);
    }

    virtual char getSymbol() const = 0;

    // Stores moves into arrays, returns number of moves
    virtual int getMoves(int movesR[], int movesC[]) = 0;
};
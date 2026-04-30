#include "Test.hpp"
#include <iostream>

#include "Pawn.hpp"
#include "Rook.hpp"
#include "Knight.hpp"
#include "Bishop.hpp"
#include "Queen.hpp"
#include "King.hpp"

using std::cout;
using std::endl;

// --------------------------------------------------
// Helper function to check if a move exists
// --------------------------------------------------
bool Test::containsMove(int movesR[], int movesC[], int count, int targetR, int targetC)
{
    for (int i = 0; i < count; i++)
    {
        if (movesR[i] == targetR && movesC[i] == targetC)
            return true;
    }
    return false;
}

// --------------------------------------------------
// Test 1: Pawn forward move
// --------------------------------------------------
void Test::testPawnForward()
{
    Pawn pawn(0, 6, 0); // white pawn at (6,0)

    int movesR[30], movesC[30];
    Piece* dummyBoard[8][8] = { nullptr };
    int count = pawn.getMoves(movesR, movesC, dummyBoard);

    if (containsMove(movesR, movesC, count, 5, 0))
        cout << "PASS: Pawn forward move exists" << endl;
    else
        cout << "FAIL: Pawn forward move missing" << endl;
}

// --------------------------------------------------
// Test 2: Pawn diagonal move
// --------------------------------------------------
void Test::testPawnDiagonal()
{
    Pawn pawn(0, 6, 3);

    int movesR[30], movesC[30];
    Piece* dummyBoard[8][8] = { nullptr };

    Pawn enemy1(1, 5, 2);
    Pawn enemy2(1, 5, 4);

    dummyBoard[5][2] = &enemy1;
    dummyBoard[5][4] = &enemy2;

    // NOW compute moves
    int count = pawn.getMoves(movesR, movesC, dummyBoard);

    if (containsMove(movesR, movesC, count, 5, 2) &&
        containsMove(movesR, movesC, count, 5, 4))
        cout << "PASS: Pawn diagonal moves exist" << endl;
    else
        cout << "FAIL: Pawn diagonal moves missing" << endl;
}

// --------------------------------------------------
// Test 3: Rook horizontal moves
// --------------------------------------------------
void Test::testRookMoves()
{
    Rook rook(0, 4, 4);

    int movesR[30], movesC[30];
    Piece* dummyBoard[8][8] = { nullptr };
    int count = rook.getMoves(movesR, movesC, dummyBoard);

    if (containsMove(movesR, movesC, count, 4, 0) &&
        containsMove(movesR, movesC, count, 4, 7))
        cout << "PASS: Rook horizontal moves valid" << endl;
    else
        cout << "FAIL: Rook movement incorrect" << endl;
}

// --------------------------------------------------
// Test 4: Knight L-shaped moves
// --------------------------------------------------
void Test::testKnightMoves()
{
    Knight knight(0, 4, 4);

    int movesR[30], movesC[30];
    Piece* dummyBoard[8][8] = { nullptr };
    int count = knight.getMoves(movesR, movesC, dummyBoard);

    if (containsMove(movesR, movesC, count, 6, 5) &&
        containsMove(movesR, movesC, count, 2, 3))
        cout << "PASS: Knight moves valid" << endl;
    else
        cout << "FAIL: Knight movement incorrect" << endl;
}

// --------------------------------------------------
// Test 5: King moves
// --------------------------------------------------
void Test::testKingMoves()
{
    King king(0, 4, 4);

    int movesR[30], movesC[30];
    Piece* dummyBoard[8][8] = { nullptr };
    int count = king.getMoves(movesR, movesC, dummyBoard);

    if (containsMove(movesR, movesC, count, 5, 5) &&
        containsMove(movesR, movesC, count, 3, 4))
        cout << "PASS: King moves valid" << endl;
    else
        cout << "FAIL: King movement incorrect" << endl;
}

void Test::runAllTests()
{
    cout << "Running test cases..." << endl;
    cout << endl;

    testPawnForward();
    testPawnDiagonal();
    testRookMoves();
    testKnightMoves();
    testKingMoves();

    cout << endl;
    cout << "All tests completed." << endl;
}

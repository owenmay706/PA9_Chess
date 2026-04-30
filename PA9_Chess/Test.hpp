#pragma once

// Run all five test cases for the chess project!
class Test
{
public:
    // Entry point for all test cases
    static void runAllTests();

private:
    // Helper functions for individual tests 
     //(kept private; called by runAllTests)
    static void testPawnForward();
    static void testPawnDiagonal();
    static void testRookMoves();
    static void testKnightMoves();
    static void testKingMoves();

    // Small helper function used by multiple tests
    static bool containsMove(int movesR[], int movesC[], int count,
        int targetR, int targetC);
};
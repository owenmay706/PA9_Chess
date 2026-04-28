#pragma once

#include <SFML/Graphics.hpp>

// Constants
const int BOARD_SIZE = 8;
const float SQUARE_SIZE = 100.0f;

class ChessBoard
{
private:
    sf::RectangleShape squares[BOARD_SIZE][BOARD_SIZE];

public:
    // Constructor
    ChessBoard();

    // Function to draw the board to the provided window
    void draw(sf::RenderWindow& window);

    // Helper to find the center of square
    sf::Vector2f getSquareCenter(int row, int col) const;
};
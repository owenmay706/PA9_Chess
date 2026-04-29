#include "Board.hpp"

ChessBoard::ChessBoard()
{
    float offsetX = (1920 - BOARD_SIZE * SQUARE_SIZE) / 2.0f;
    float offsetY = (1080 - BOARD_SIZE * SQUARE_SIZE) / 2.0f;

    for (int row = 0; row < BOARD_SIZE; ++row)
    {
        for (int col = 0; col < BOARD_SIZE; ++col)
        {
            squares[row][col].setSize(sf::Vector2f(SQUARE_SIZE, SQUARE_SIZE));
            squares[row][col].setPosition(sf::Vector2f(
                offsetX + col * SQUARE_SIZE,
                offsetY + row * SQUARE_SIZE));


            if ((row + col) % 2 == 0)
            {
                squares[row][col].setFillColor(sf::Color(240, 217, 181)); // Light
            }
            else
            {
                squares[row][col].setFillColor(sf::Color(181, 136, 99));  // Dark
            }
        }
    }
}

void ChessBoard::draw(sf::RenderWindow& window)
{
    for (int row = 0; row < BOARD_SIZE; ++row)
    {
        for (int col = 0; col < BOARD_SIZE; ++col)
        {
            window.draw(squares[row][col]);
        }
    }
}

sf::Vector2f ChessBoard::getSquareCenter(int row, int col) const
{
    float centerX = (col * SQUARE_SIZE) + (SQUARE_SIZE / 2.0f);
    float centerY = (row * SQUARE_SIZE) + (SQUARE_SIZE / 2.0f);

    return sf::Vector2f(centerX, centerY);
}

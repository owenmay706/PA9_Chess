#include "Board.hpp"

ChessBoard::ChessBoard()
{
    for (int row = 0; row < BOARD_SIZE; ++row)
    {
        for (int col = 0; col < BOARD_SIZE; ++col)
        {
            squares[row][col].setSize(sf::Vector2f(SQUARE_SIZE, SQUARE_SIZE));
            squares[row][col].setPosition(sf::Vector2f(static_cast<float>(col) * SQUARE_SIZE, static_cast<float>(row) * SQUARE_SIZE));

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
main.cpp
#include "Board.hpp"
#include "SFML/Graphics.hpp"

// window should be 1920, 1080
// each square 100 pixels
int main()
{
    sf::RenderWindow window(sf::VideoMode({ static_cast<unsigned int>(BOARD_SIZE * SQUARE_SIZE),
        static_cast<unsigned int>(BOARD_SIZE * SQUARE_SIZE) }), "SFML Chess");

    ChessBoard board;

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        window.clear();
        board.draw(window);
        window.display();
    }

    return 0;
}

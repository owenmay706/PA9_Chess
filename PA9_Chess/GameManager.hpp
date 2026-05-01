#pragma once

#include "Menu.hpp"
#include "Piece.hpp"
#include "board.hpp"
#include "Renderer.hpp"
#include "Pawn.hpp"
#include "Rook.hpp"
#include "Queen.hpp"
#include "King.hpp"
#include "Bishop.hpp"
#include "knight.hpp"
#include "NetworkManager.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class GameManager {
private:
    sf::RenderWindow window;

    Piece* gameBoard[8][8];

    int turn = 0;
    bool gameOver = false;
    bool multiplayerMode = false;
    bool myTurn = true;
    bool flipped = false;   // true for the joining (Black) player

    sf::Font font;
    std::string winnerText;

    Piece* selectedPiece = nullptr;

    int validMoveRows[30];
    int validMoveCols[30];
    int validMoveCount = 0;

    NetworkManager network;

public:

    GameManager()
        : window(sf::VideoMode({ 1920, 1080 }), "Chess")
    {
        for (int r = 0; r < 8; r++)
            for (int c = 0; c < 8; c++)
                gameBoard[r][c] = nullptr;
    }

    void StartGame()
    {
        Menu menu;
        MenuResult result = menu.handleInput(window);

        if (result == MenuResult::Play)
        {
            multiplayerMode = false;
            playGame();
        }
        else if (result == MenuResult::Multiplayer)
        {
            multiplayerMode = true;

            char choice;
            std::cout << "Host (h) or Join (j): ";
            std::cin >> choice;

            if (choice == 'h')
            {
                std::cout << "Waiting for opponent to connect on port 53000...\n";
                network.hostGame(53000);
                myTurn = true;
                flipped = false;
                turn = 0;
            }
            else
            {
                std::string ip;
                std::cout << "Enter host IP address (or 127.0.0.1 for same machine): ";
                std::cin >> ip;

                network.joinGame(ip, 53000);
                myTurn = false;
                flipped = true;   // joining player sees the board from Black's side
                turn = 0;
            }

            playGame();
        }
        else
        {
            window.close();
        }
    }

    void playGame()
    {
        ChessBoard board;
        Renderer render;
        render.loadTextures();

        if (!font.openFromFile("RobotoRegular.ttf"))
            std::cout << "Font failed\n";

        initBoard();

        while (window.isOpen())
        {
            if (multiplayerMode && !myTurn && !gameOver)
            {
                int fr, fc, tr, tc;

                if (network.receiveMove(fr, fc, tr, tc))
                {
                    Piece* p = gameBoard[fr][fc];

                    if (p)
                    {
                        movePiece(p, tr, tc);
                        turn = 1 - turn;
                        myTurn = true;
                    }
                }
            }

            while (auto event = window.pollEvent())
            {
                if (event->is<sf::Event::Closed>())
                    window.close();

                if (const auto* key = event->getIf<sf::Event::KeyPressed>())
                {
                    if (key->code == sf::Keyboard::Key::Escape && gameOver)
                        window.close();

                    if (key->code == sf::Keyboard::Key::R && gameOver)
                        restartGame();
                }

                if (!gameOver)
                {
                    if (const auto* mouse = event->getIf<sf::Event::MouseButtonPressed>())
                    {
                        if (mouse->button == sf::Mouse::Button::Left)
                            handleClick(mouse->position.x, mouse->position.y);
                    }
                }
            }

            if (gameOver)
                drawWinnerScreen();
            else
                drawBoard(board, render);
        }
    }

    void drawBoard(ChessBoard& board, Renderer& render)
    {
        window.clear();
        board.draw(window);
        drawTurnText();
        renderPieces(render);
        window.display();
    }

    void drawWinnerScreen()
    {
        window.clear(sf::Color::Black);

        sf::Text text(font);
        text.setString(winnerText);
        text.setCharacterSize(80);
        text.setFillColor(sf::Color::White);

        window.draw(text);
        window.display();
    }

    void drawTurnText()
    {
        sf::Text text(font);
        text.setString(turn == 0 ? "White Turn" : "Black Turn");
        text.setCharacterSize(40);
        text.setFillColor(sf::Color::White);
        window.draw(text);
    }

    void renderPieces(Renderer& render)
    {
        for (int r = 0; r < 8; r++)
            for (int c = 0; c < 8; c++)
                if (gameBoard[r][c])
                {
                    int displayRow = flipped ? (7 - r) : r;
                    int displayCol = flipped ? (7 - c) : c;
                    render.drawChessPiece(window, getPieceName(gameBoard[r][c]), displayRow, displayCol);
                }
    }

    std::string getPieceName(Piece* piece)
    {
        std::string color = (piece->getTeam() == 0) ? "white_" : "black_";

        switch (piece->getSymbol())
        {
        case 'P': case 'p': return color + "pawn";
        case 'R': case 'r': return color + "rook";
        case 'N': case 'n': return color + "knight";
        case 'B': case 'b': return color + "bishop";
        case 'Q': case 'q': return color + "queen";
        case 'K': case 'k': return color + "king";
        }
        return "";
    }

    void handleClick(int x, int y)
    {
        float offsetX = (1920 - 800) / 2.0f;
        float offsetY = (1080 - 800) / 2.0f;

        int col = (x - offsetX) / 100;
        int row = (y - offsetY) / 100;

        // Un-flip click coordinates for the joining (Black) player
        if (flipped)
        {
            row = 7 - row;
            col = 7 - col;
        }

        if (!inBounds(row, col))
            return;

        // In multiplayer, block input when it is not this player's turn
        if (multiplayerMode && !myTurn)
            return;

        if (!selectedPiece)
        {
            Piece* p = gameBoard[row][col];

            if (p && p->getTeam() == turn)
            {
                selectedPiece = p;
                validMoveCount = p->getMoves(validMoveRows, validMoveCols, gameBoard);
            }
        }
        else
        {
            // If the player clicks one of their own pieces, reselect it instead
            Piece* target = gameBoard[row][col];
            if (target && target->getTeam() == turn)
            {
                selectedPiece = target;
                validMoveCount = target->getMoves(validMoveRows, validMoveCols, gameBoard);
                return;
            }

            if (isValidMove(row, col))
            {
                // Capture from/to BEFORE movePiece changes the piece's position
                int fr = selectedPiece->getRow();
                int fc = selectedPiece->getCol();

                movePiece(selectedPiece, row, col);
                turn = 1 - turn;

                if (multiplayerMode)
                {
                    network.sendMove(fr, fc, row, col);
                    myTurn = false;
                }
            }

            selectedPiece = nullptr;
            validMoveCount = 0;
        }
    }

    void movePiece(Piece* piece, int r, int c)
    {
        int fr = piece->getRow();
        int fc = piece->getCol();

        if (gameBoard[r][c] &&
            (gameBoard[r][c]->getSymbol() == 'K' || gameBoard[r][c]->getSymbol() == 'k'))
        {
            winnerText = (piece->getTeam() == 0) ? "White Wins!" : "Black Wins!";
            gameOver = true;
        }

        delete gameBoard[r][c];

        gameBoard[r][c] = piece;
        gameBoard[fr][fc] = nullptr;

        piece->setPosition(r, c);
    }

    void initBoard()
    {
        for (int c = 0; c < 8; c++)
        {
            gameBoard[1][c] = new Pawn(1, 1, c);
            gameBoard[6][c] = new Pawn(0, 6, c);
        }

        gameBoard[0][0] = new Rook(1, 0, 0);
        gameBoard[0][7] = new Rook(1, 0, 7);
        gameBoard[7][0] = new Rook(0, 7, 0);
        gameBoard[7][7] = new Rook(0, 7, 7);

        gameBoard[0][1] = new Knight(1, 0, 1);
        gameBoard[0][6] = new Knight(1, 0, 6);
        gameBoard[7][1] = new Knight(0, 7, 1);
        gameBoard[7][6] = new Knight(0, 7, 6);

        gameBoard[0][2] = new Bishop(1, 0, 2);
        gameBoard[0][5] = new Bishop(1, 0, 5);
        gameBoard[7][2] = new Bishop(0, 7, 2);
        gameBoard[7][5] = new Bishop(0, 7, 5);

        gameBoard[0][3] = new Queen(1, 0, 3);
        gameBoard[7][3] = new Queen(0, 7, 3);

        gameBoard[0][4] = new King(1, 0, 4);
        gameBoard[7][4] = new King(0, 7, 4);
    }

    void restartGame()
    {
        for (int r = 0; r < 8; r++)
            for (int c = 0; c < 8; c++)
            {
                delete gameBoard[r][c];
                gameBoard[r][c] = nullptr;
            }

        gameOver = false;
        turn = 0;
        myTurn = !flipped;   // host (White) goes first after restart too
        selectedPiece = nullptr;
        validMoveCount = 0;

        initBoard();
    }

    bool isValidMove(int r, int c)
    {
        for (int i = 0; i < validMoveCount; i++)
            if (validMoveRows[i] == r && validMoveCols[i] == c)
                return true;

        return false;
    }

    bool inBounds(int r, int c)
    {
        return r >= 0 && r < 8 && c >= 0 && c < 8;
    }
};
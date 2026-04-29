//this file will contain the class gamemanager, this class creates the menu, and will call other functions to run the game.
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

class GameManager {
private:
	//the game manager will store things from the other classes, since those are not done yet I will add them later.
	sf::RenderWindow window;
	int turn; //0 for white, 1 for black
	Piece* gameBoard[8][8]; 

    bool gameOver = false;

    sf::Font font;

    std::string winnerText = "";

    Piece* selectedPiece = nullptr;
    int validMoveRows[30];
    int validMoveCols[30];
    int validMoveCount = 0;

public:

	//constructor, will contain more once the other constructors are complete
	GameManager() : window(sf::VideoMode({ 1920, 1080 }), "Chess"), turn(0) {}
	
	void StartGame() {

		
		Menu menu;

		MenuResult result = menu.handleInput(window);

		if (result == MenuResult::Play) {
			playGame();
		}
		else {
			window.close();
		}
	}

    void playGame() {
        ChessBoard board;
        Renderer render;
        render.loadTextures();
        if (!font.openFromFile("RobotoRegular.ttf"))
            std::cout << "Failed to load font!" << std::endl;
        initBoard();

        while (window.isOpen()) {
            while (auto event = window.pollEvent()) {
                if (event->is<sf::Event::Closed>())
                    window.close();

                if (const auto* keyEvent = event->getIf<sf::Event::KeyPressed>()) {
                    if (keyEvent->code == sf::Keyboard::Key::Escape && gameOver)
                        window.close();
                }

                if (!gameOver) {
                    if (const auto* mouseEvent = event->getIf<sf::Event::MouseButtonPressed>()) {
                        if (mouseEvent->button == sf::Mouse::Button::Left)
                            handleClick(mouseEvent->position.x, mouseEvent->position.y);
                    }
                }
            }

            if (gameOver)
                drawWinnerScreen();
            else
                drawBoard(board, render);
        }
    }


    void initBoard() {
        // Clear board first
        for (int r = 0; r < 8; r++)
            for (int c = 0; c < 8; c++) {
                gameBoard[r][c] = nullptr;
                delete gameBoard[r][c];
            }
              
        

        // Pawns
        for (int c = 0; c < 8; c++) {
            gameBoard[1][c] = new Pawn(1, 1, c); // black
            gameBoard[6][c] = new Pawn(0, 6, c); // white
        }

        // Rooks
        gameBoard[0][0] = new Rook(1, 0, 0); //team (1 = black, 0 = white), row, column starting at 0,0 top left
        gameBoard[0][7] = new Rook(1, 0, 7);
        gameBoard[7][0] = new Rook(0, 7, 0);
        gameBoard[7][7] = new Rook(0, 7, 7);

        // Knights
        gameBoard[0][1] = new Knight(1, 0, 1);
        gameBoard[0][6] = new Knight(1, 0, 6);
        gameBoard[7][1] = new Knight(0, 7, 1);
        gameBoard[7][6] = new Knight(0, 7, 6);

        // Bishops
        gameBoard[0][2] = new Bishop(1, 0, 2);
        gameBoard[0][5] = new Bishop(1, 0, 5);
        gameBoard[7][2] = new Bishop(0, 7, 2);
        gameBoard[7][5] = new Bishop(0, 7, 5);

        // Queens
        gameBoard[0][3] = new Queen(1, 0, 3);
        gameBoard[7][3] = new Queen(0, 7, 3);

        // Kings
        gameBoard[0][4] = new King(1, 0, 4);
        gameBoard[7][4] = new King(0, 7, 4);
    }
    
    void drawBoard(ChessBoard& board, Renderer& render) {
        window.clear();
        board.draw(window);
        renderPieces(render);
        drawTurnText();
        window.display();
    }

    void drawTurnText() {
        sf::Text turnText(font);
        turnText.setString(turn == 0 ? "White's Turn" : "Black's Turn");
        turnText.setCharacterSize(40);
        turnText.setFillColor(sf::Color::White);

        // Center it horizontally, place it just above the board
        float offsetX = (1920 - 8 * TILE_SIZE) / 2.0f;
        float offsetY = (1080 - 8 * TILE_SIZE) / 2.0f;

        sf::FloatRect textBounds = turnText.getLocalBounds();
        float textX = offsetX + (8 * TILE_SIZE) / 2.0f - textBounds.size.x / 2.0f;
        float textY = offsetY - 60.0f; // 60 pixels above the board

        turnText.setPosition(sf::Vector2f(textX, textY));
        window.draw(turnText);
    }



    void renderPieces(Renderer& render) {
        for (int r = 0; r < 8; r++) {
            for (int c = 0; c < 8; c++) {
                if (gameBoard[r][c] != nullptr) {
                    std::string pieceName = getPieceName(gameBoard[r][c]);
                    render.drawChessPiece(window, pieceName, r, c);
                }
            }
        }
    }

    std::string getPieceName(Piece* piece) {
        std::string color = (piece->getTeam() == 0) ? "white_" : "black_";
        switch (piece->getSymbol()) {
        case 'P': case 'p': return color + "pawn";
        case 'R': case 'r': return color + "rook";
        case 'N': case 'n': return color + "knight";
        case 'B': case 'b': return color + "bishop";
        case 'Q': case 'q': return color + "queen";
        case 'K': case 'k': return color + "king";
        default: return "";
        }
    }

    void handleClick(int mouseX, int mouseY) {
        // Convert pixel position to board grid position
        float offsetX = (1920 - 8 * TILE_SIZE) / 2.0f;
        float offsetY = (1080 - 8 * TILE_SIZE) / 2.0f;

        int col = (mouseX - offsetX) / TILE_SIZE;
        int row = (mouseY - offsetY) / TILE_SIZE;

        if (!inBounds(row, col)) return;

        if (selectedPiece == nullptr) {
            // First click — select a piece if it belongs to current player
            Piece* clicked = gameBoard[row][col];
            if (clicked != nullptr && clicked->getTeam() == turn) {
                selectedPiece = clicked;
                validMoveCount = selectedPiece->getMoves(validMoveRows, validMoveCols, gameBoard);
            }
        }
        else {
            // Second click — try to move to this square
            if (isValidMove(row, col)) {
                movePiece(selectedPiece, row, col);
                turn = 1 - turn; // swap turn
            }
            // Deselect regardless
            selectedPiece = nullptr;
            validMoveCount = 0;
        }
    }

    bool isValidMove(int row, int col) {
        for (int i = 0; i < validMoveCount; i++) {
            if (validMoveRows[i] == row && validMoveCols[i] == col)
                return true;
        }
        return false;
    }

    void movePiece(Piece* piece, int toRow, int toCol) {
        int fromRow = piece->getRow();
        int fromCol = piece->getCol();

        // Delete captured piece if present, also checking for king capture
        if (gameBoard[toRow][toCol] != nullptr) {
            char sym = gameBoard[toRow][toCol]->getSymbol();
            if (sym == 'K' || sym == 'k') {
                int winner = piece->getTeam(); // whoever moved wins
                delete gameBoard[toRow][toCol];
                gameBoard[toRow][toCol] = piece;
                gameBoard[fromRow][fromCol] = nullptr;
                piece->setPosition(toRow, toCol);
                endGame(winner);
                return;
            }
            delete gameBoard[toRow][toCol];
        }

        // Move in array
        gameBoard[toRow][toCol] = piece;
        gameBoard[fromRow][fromCol] = nullptr;

        // Update piece's internal position
        piece->setPosition(toRow, toCol);

        // Mark pawn as moved
        if (piece->getSymbol() == 'P' || piece->getSymbol() == 'p') {
            static_cast<Pawn*>(piece)->setMoved();
        }
    }

    void endGame(int winner) {
        gameOver = true;
        winnerText = (winner == 0) ? "White Wins!" : "Black Wins!";
    }

    void drawWinnerScreen() {
        window.clear(sf::Color::Black);

        // Winner text
        sf::Text winner(font);
        winner.setString(winnerText);
        winner.setCharacterSize(80);
        winner.setFillColor(sf::Color::White);
        sf::FloatRect wb = winner.getLocalBounds();
        winner.setPosition(sf::Vector2f(
            1920 / 2.0f - wb.size.x / 2.0f,
            1080 / 2.0f - wb.size.y / 2.0f - 40.0f
        ));

        // Prompt text
        sf::Text prompt(font);
        prompt.setString("Press Escape to Exit");
        prompt.setCharacterSize(40);
        prompt.setFillColor(sf::Color(180, 180, 180));
        sf::FloatRect pb = prompt.getLocalBounds();
        prompt.setPosition(sf::Vector2f(
            1920 / 2.0f - pb.size.x / 2.0f,
            1080 / 2.0f + 40.0f
        ));

        window.draw(winner);
        window.draw(prompt);
        window.display();
    }

    bool inBounds(int row, int col) {
        return (row >= 0 && row < 8 && col >= 0 && col < 8);
    }

};

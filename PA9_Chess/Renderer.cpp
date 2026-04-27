#include "Renderer.hpp"
#include <iostream>
#include <algorithm>

Renderer::Renderer()
{
	// Renderer constructor stays empty, because the only data members that need to be initialized are
	// the textures, which takes place in a separate function called loadTexture() to allow for proper
	// error handling and to keep the initializaiton of objects simple!
}

bool Renderer::loadTextures()
{
	// Assign each piece texture to a specific string title in the Renderer's map structure once,
	// then store it paired with that string name for future reference!

	if (!textures["white_pawn"].loadFromFile("../assets/white_pawn_scaled.png"))
	{
		return false;
	}
	if (!textures["black_pawn"].loadFromFile("../assets/black_pawn_scaled.png"))
	{
		return false;
	}

	if (!textures["white_rook"].loadFromFile("../assets/white_rook_scaled.png"))
	{
		return false;
	}
	if (!textures["black_rook"].loadFromFile("../assets/black_rook_scaled.png"))
	{
		return false;
	}

	if (!textures["white_knight"].loadFromFile("../assets/white_knight_scaled.png"))
	{
		return false;
	}
	if (!textures["black_knight"].loadFromFile("../assets/black_knight_scaled.png"))
	{
		return false;
	}

	if (!textures["white_bishop"].loadFromFile("../assets/white_bishop_scaled.png"))
	{
		return false;
	}
	if (!textures["black_bishop"].loadFromFile("../assets/black_bishop_scaled.png"))
	{
		return false;
	}

	if (!textures["white_king"].loadFromFile("../assets/white_king_scaled.png"))
	{
		return false;
	}
	if (!textures["black_king"].loadFromFile("../assets/black_king_scaled.png"))
	{
		return false;
	}

	if (!textures["white_queen"].loadFromFile("../assets/white_queen_scaled.png"))
	{
		return false;
	}
	if (!textures["black_queen"].loadFromFile("../assets/black_queen_scaled.png"))
	{
		return false;
	}

	// If every pawn texture image was loaded correctly, the piece loading process was successful!
	// So, return true!
	return true;
}

// A single function intended to render each chess piece, depending on the parameter
// passed in for the piece name!

// Sidenote: the window reference parameter is not passed in as a constant value because
// sprite drawing operations modify the internal state of the window, meaning that
// the window parameter cannot be marked as const!
void Renderer::drawChessPiece(sf::RenderWindow& window, const std::string& pieceName,
							  int row, int column)
{
	if (textures.find(pieceName) == textures.end())
	{
		std::cout << "Uh oh, the texture was not found for the " << pieceName << std::endl;
		return;
	}
	
	// Create a sprite corresponding to the texture value related to the piece name
	// that is passed in the reference string parameter!
	sf::Sprite sprite(textures[pieceName]);

	// Store width and height for the current piece based on the horizontal and
	// vertical size values of the original image!
	float width = textures[pieceName].getSize().x;
	float height = textures[pieceName].getSize().y;

	// Adjust the horizontal and vertical scale of the rendered piece image
	// based on the size of the square chess board tiles (this is versatile,
	// depending on the size of the tiles)!
	float scale = std::min(TILE_SIZE / width, TILE_SIZE / height);
	sprite.setScale(sf::Vector2f(scale, scale));

	// Position the piece on the grid, depending on the row and column values passed in,
	// and adjust to the size of the chess board tiles!
	sprite.setPosition(sf::Vector2f(column * TILE_SIZE, row * TILE_SIZE));

	window.draw(sprite);
}

void Renderer::renderAllPieces(sf::RenderWindow& window)
{
	// Draw the white pawn chess piece sprites!
	for (int column = 0; column < 8; column++)
	{
		drawChessPiece(window, "white_pawn", 6, column);
	}

	// Draw the black pawn chess piece sprites!
	for (int column = 0; column < 8; column++)
	{
		drawChessPiece(window, "black_pawn", 1, column);
	}

	// Draw the white rook chess piece sprites!
	drawChessPiece(window, "white_rook", 7, 0);
	drawChessPiece(window, "white_rook", 7, 7);

	// Draw the black rook chess piece sprites!
	drawChessPiece(window, "black_rook", 0, 0);
	drawChessPiece(window, "black_rook", 0, 7);

	// Draw the white knight chess piece sprites!
	drawChessPiece(window, "white_knight", 7, 1);
	drawChessPiece(window, "white_knight", 7, 6);

	// Draw the black knight chess piece sprites!
	drawChessPiece(window, "black_knight", 0, 1);
	drawChessPiece(window, "black_knight", 0, 6);

	// Draw the white bishop chess piece sprites!
	drawChessPiece(window, "white_bishop", 7, 2);
	drawChessPiece(window, "white_bishop", 7, 5);

	// Draw the black bishop chess piece sprites!
	drawChessPiece(window, "black_bishop", 0, 2);
	drawChessPiece(window, "black_bishop", 0, 5);

	// Draw the white queen chess piece sprite!
	drawChessPiece(window, "white_queen", 7, 3);
	// Draw the black queen chess piece sprite!
	drawChessPiece(window, "black_queen", 0, 3);

	// Draw the white king chess piece sprite!
	drawChessPiece(window, "white_king", 7, 4);
	// Draw the black king chess piece sprite!
	drawChessPiece(window, "black_king", 0, 4);
}
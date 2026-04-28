#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <string>

class Renderer
{
public:
	Renderer();
	bool loadTextures();
	void drawChessPiece(sf::RenderWindow& window, const std::string& pieceName,
						int row, int column);
	void renderAllPieces(sf::RenderWindow& window);


private:
	// Use a container called a map that stores data in key-value pairs, to
	// avoid needing to reload textures every frame!
	std::map<std::string, sf::Texture> textures;

	const int TILE_SIZE = 100;
};
#include "Renderer.hpp"

#include "SFML/Graphics.hpp"
#include <iostream> // This library is included to see debug output!
#include <algorithm> // This library is included for using the std::min keyword!
#include "GameManager.hpp"

using std::endl;
using std::cout;
using std::min;

int main(void) {
	GameManager game;
	game.StartGame();
}




//int main(void) {
//    sf::RenderWindow window(sf::VideoMode({ 800, 800 }), "SFML works!");
//    
//    // Check that each chess piece texture was loaded properly (if not, print
//    // an error message and end the program with a -1 return value)!
//    Renderer renderer;
//    if (!renderer.loadTextures())
//    {
//        std::cout << "Oh no, at least one texture couldn't be loaded!" << endl;
//        return -1;
//    }
//
//    // Continue to dipslay a separate game window until the user exits the screen!
//    while (window.isOpen())
//    {
//        while (const std::optional event = window.pollEvent())
//        {
//            if (event->is<sf::Event::Closed>())
//                window.close();
//        }
//
//        // Clear existing images in the window before drawing the new frame!
//        window.clear();
//
//        // Render each chess piece in the game window!
//        renderer.renderAllPieces(window);
//        
//        // Display the updated frame!
//        window.display();
//    }
//}
//
//    
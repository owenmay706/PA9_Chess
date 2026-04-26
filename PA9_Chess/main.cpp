#include "SFML/Graphics.hpp"
#include <iostream> // This library is included to see debug output!
#include <algorithm> // This library is included for using the std::min keyword!

using std::endl;
using std::cout;
using std::min;

int main(void) {
    sf::RenderWindow window(sf::VideoMode({ 200, 200 }), "SFML works!");


    // Load a texture from the assets folder, containing images of chess pieces!
    sf::Texture pawnTexture;

    // Attempt to load the image file, then print an error message if the image
    // could not be loaded correctly!
    // "../" moves up one file directory becasuethe executable runs inside
    // a nested project folder!
    if (!pawnTexture.loadFromFile("../assets/white_king.png"))
    {
        cout << "Error: failed to load assets/white_pawn.png" << endl;
        return -1;
    }
    // Since there was no failure with loading the image file, show a success debug message!
    cout << "Success: Texture loaded correctly!" << endl;

    // Create a sprite that will use the successfully loaded texture.
    // A sprite is the 2D object that gets drawn and displayed on the screen!
    sf::Sprite pawnSprite(pawnTexture);

    // Place the sprite in the top left corner of the window.
    // The SFML library represents (0,0) as the top left pixel!
    pawnSprite.setPosition(sf::Vector2f(0.f, 0.f));

    // Get the original width and height of the white pawn texture!
    float textureWidth = static_cast<float>(pawnTexture.getSize().x);
    float textureHeight = static_cast<float>(pawnTexture.getSize().y);

    // Compute scale factors for both dimensions!
    float scaleX = 100.0f / textureWidth;
    float scaleY = 100.0f / textureHeight;

    // Choose a smaller scale inside a 100x100 window to preserve the 
    // original image's aspect ratio, preventing the image from appearing
    // stretched or squished!
    float uniformScale = min(scaleX, scaleY);

    // Apply the same small scale to both axes to preserve the image's
    // original aspect ratio!
    pawnSprite.setScale(sf::Vector2f(uniformScale, uniformScale));

    // Existing test shape (keeping this code for now, to confirm that an image
    // is properly displayed on the screen)!
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // Clear existing images in the window before drawing the new frame
        window.clear();

        // Draw the white pawn chess piece sprite instead of the test circle!
        window.draw(pawnSprite);
        
        // Display the updated frame!
        window.display();
    }
}
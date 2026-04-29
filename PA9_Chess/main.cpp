#include "Renderer.hpp"

#include "SFML/Graphics.hpp"
#include <iostream> // This library is included to see debug output!
#include <algorithm> // This library is included for using the std::min keyword!

using std::endl;
using std::cout;
using std::min;


int main(void) {
    sf::RenderWindow window(sf::VideoMode({ 800, 800 }), "SFML works!");
    
    // Check that each chess piece texture was loaded properly (if not, print
    // an error message and end the program with a -1 return value)!
    Renderer renderer;
    if (!renderer.loadTextures())
    {
        std::cout << "Oh no, at least one texture couldn't be loaded!" << endl;
        return -1;
    }

    // Continue to dipslay a separate game window until the user exits the screen!
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // Clear existing images in the window before drawing the new frame!
        window.clear();

        // Render each chess piece in the game window!
        renderer.renderAllPieces(window);
        
        // Display the updated frame!
        window.display();
    }
}

// For reference: previous, hard-coded approach to the program (very long and repetitive):

//// ------------------------------------------------------------------------
    //// White pawn one setup:

    //// Load a texture from the assets folder, containing images of chess pieces!
    //sf::Texture whitePawnTexture;

    //// Attempt to load the image file, then print an error message if the image
    //// could not be loaded correctly!
    //// "../" moves up one file directory becasuethe executable runs inside
    //// a nested project folder!
    //if (!whitePawnTexture.loadFromFile("../assets/white_pawn_scaled.png"))
    //{
    //    cout << "Error: failed to load assets/white_pawn_scaled.png" << endl;
    //    return -1;
    //}
    //// Since there was no failure with loading the image file, show a success debug message!
    //cout << "Success: Texture loaded correctly!" << endl;

    //// Create a sprite that will use the successfully loaded texture.
    //// A sprite is the 2D object that gets drawn and displayed on the screen!
    //sf::Sprite whitePawnSpriteOne(whitePawnTexture);
    //sf::Sprite whitePawnSpriteTwo(whitePawnTexture);
    //sf::Sprite whitePawnSpriteThree(whitePawnTexture);
    //sf::Sprite whitePawnSpriteFour(whitePawnTexture);
    //sf::Sprite whitePawnSpriteFive(whitePawnTexture);
    //sf::Sprite whitePawnSpriteSix(whitePawnTexture);
    //sf::Sprite whitePawnSpriteSeven(whitePawnTexture);
    //sf::Sprite whitePawnSpriteEight(whitePawnTexture);

    //// ------------------------------------------------------------------------

    //// ------------------------------------------------------------------------
    //// Black pawn setup:

    //// Load a texture from the assets folder, containing images of chess pieces!
    //sf::Texture blackPawnTexture;

    //// Attempt to load the image file, then print an error message if the image
    //// could not be loaded correctly!
    //// "../" moves up one file directory becasuethe executable runs inside
    //// a nested project folder!
    //if (!blackPawnTexture.loadFromFile("../assets/black_pawn_scaled.png"))
    //{
    //    cout << "Error: failed to load assets/black_pawn_scaled.png" << endl;
    //    return -1;
    //}
    //// Since there was no failure with loading the image file, show a success debug message!
    //cout << "Success: Texture loaded correctly!" << endl;

    //// Create a sprite that will use the successfully loaded texture.
    //// A sprite is the 2D object that gets drawn and displayed on the screen!
    //sf::Sprite blackPawnSpriteOne(blackPawnTexture);
    //sf::Sprite blackPawnSpriteTwo(blackPawnTexture);
    //sf::Sprite blackPawnSpriteThree(blackPawnTexture);
    //sf::Sprite blackPawnSpriteFour(blackPawnTexture);
    //sf::Sprite blackPawnSpriteFive(blackPawnTexture);
    //sf::Sprite blackPawnSpriteSix(blackPawnTexture);
    //sf::Sprite blackPawnSpriteSeven(blackPawnTexture);
    //sf::Sprite blackPawnSpriteEight(blackPawnTexture);

    //// ------------------------------------------------------------------------

    //// ------------------------------------------------------------------------
    //// White rook setup:

    //// Load a texture from the assets folder, containing images of chess pieces!
    //sf::Texture whiteRookTexture;

    //// Attempt to load the image file, then print an error message if the image
    //// could not be loaded correctly!
    //// "../" moves up one file directory becasuethe executable runs inside
    //// a nested project folder!
    //if (!whiteRookTexture.loadFromFile("../assets/white_rook_scaled.png"))
    //{
    //    cout << "Error: failed to load assets/white_rook_scaled.png" << endl;
    //    return -1;
    //}
    //// Since there was no failure with loading the image file, show a success debug message!
    //cout << "Success: Texture loaded correctly!" << endl;

    //// Create a sprite that will use the successfully loaded texture.
    //// A sprite is the 2D object that gets drawn and displayed on the screen!
    //sf::Sprite whiteRookSpriteOne(whiteRookTexture);
    //sf::Sprite whiteRookSpriteTwo(whiteRookTexture);

    //// ------------------------------------------------------------------------

    //// ------------------------------------------------------------------------
    //// Black rook setup:

    //// Load a texture from the assets folder, containing images of chess pieces!
    //sf::Texture blackRookTexture;

    //// Attempt to load the image file, then print an error message if the image
    //// could not be loaded correctly!
    //// "../" moves up one file directory becasuethe executable runs inside
    //// a nested project folder!
    //if (!blackRookTexture.loadFromFile("../assets/black_rook_scaled.png"))
    //{
    //    cout << "Error: failed to load assets/black_rook_scaled.png" << endl;
    //    return -1;
    //}
    //// Since there was no failure with loading the image file, show a success debug message!
    //cout << "Success: Texture loaded correctly!" << endl;

    //// Create a sprite that will use the successfully loaded texture.
    //// A sprite is the 2D object that gets drawn and displayed on the screen!
    //sf::Sprite blackRookSpriteOne(blackRookTexture);
    //sf::Sprite blackRookSpriteTwo(blackRookTexture);

    //// ------------------------------------------------------------------------

    //// ------------------------------------------------------------------------
    //// White knight setup:

    //// Load a texture from the assets folder, containing images of chess pieces!
    //sf::Texture whiteKnightTexture;

    //// Attempt to load the image file, then print an error message if the image
    //// could not be loaded correctly!
    //// "../" moves up one file directory becasuethe executable runs inside
    //// a nested project folder!
    //if (!whiteKnightTexture.loadFromFile("../assets/white_knight_scaled.png"))
    //{
    //    cout << "Error: failed to load assets/white_knight_scaled.png" << endl;
    //    return -1;
    //}
    //// Since there was no failure with loading the image file, show a success debug message!
    //cout << "Success: Texture loaded correctly!" << endl;

    //// Create a sprite that will use the successfully loaded texture.
    //// A sprite is the 2D object that gets drawn and displayed on the screen!
    //sf::Sprite whiteKnightSpriteOne(whiteKnightTexture);
    //sf::Sprite whiteKnightSpriteTwo(whiteKnightTexture);

    //// ------------------------------------------------------------------------

    //// ------------------------------------------------------------------------
    //// Black knight setup:

    //// Load a texture from the assets folder, containing images of chess pieces!
    //sf::Texture blackKnightTexture;

    //// Attempt to load the image file, then print an error message if the image
    //// could not be loaded correctly!
    //// "../" moves up one file directory becasuethe executable runs inside
    //// a nested project folder!
    //if (!blackKnightTexture.loadFromFile("../assets/black_knight_scaled.png"))
    //{
    //    cout << "Error: failed to load assets/black_knight_scaled.png" << endl;
    //    return -1;
    //}
    //// Since there was no failure with loading the image file, show a success debug message!
    //cout << "Success: Texture loaded correctly!" << endl;

    //// Create a sprite that will use the successfully loaded texture.
    //// A sprite is the 2D object that gets drawn and displayed on the screen!
    //sf::Sprite blackKnightSpriteOne(blackKnightTexture);
    //sf::Sprite blackKnightSpriteTwo(blackKnightTexture);

    //// ------------------------------------------------------------------------

    //// ------------------------------------------------------------------------
    //// White bishop setup:

    //// Load a texture from the assets folder, containing images of chess pieces!
    //sf::Texture whiteBishopTexture;

    //// Attempt to load the image file, then print an error message if the image
    //// could not be loaded correctly!
    //// "../" moves up one file directory becasuethe executable runs inside
    //// a nested project folder!
    //if (!whiteBishopTexture.loadFromFile("../assets/white_bishop_scaled.png"))
    //{
    //    cout << "Error: failed to load assets/white_bishop_scaled.png" << endl;
    //    return -1;
    //}
    //// Since there was no failure with loading the image file, show a success debug message!
    //cout << "Success: Texture loaded correctly!" << endl;

    //// Create a sprite that will use the successfully loaded texture.
    //// A sprite is the 2D object that gets drawn and displayed on the screen!
    //sf::Sprite whiteBishopSpriteOne(whiteBishopTexture);
    //sf::Sprite whiteBishopSpriteTwo(whiteBishopTexture);

    //// ------------------------------------------------------------------------

    //// ------------------------------------------------------------------------
    //// Black bishop setup:

    //// Load a texture from the assets folder, containing images of chess pieces!
    //sf::Texture blackBishopTexture;

    //// Attempt to load the image file, then print an error message if the image
    //// could not be loaded correctly!
    //// "../" moves up one file directory becasuethe executable runs inside
    //// a nested project folder!
    //if (!blackBishopTexture.loadFromFile("../assets/black_bishop_scaled.png"))
    //{
    //    cout << "Error: failed to load assets/black_bishop_scaled.png" << endl;
    //    return -1;
    //}
    //// Since there was no failure with loading the image file, show a success debug message!
    //cout << "Success: Texture loaded correctly!" << endl;

    //// Create a sprite that will use the successfully loaded texture.
    //// A sprite is the 2D object that gets drawn and displayed on the screen!
    //sf::Sprite blackBishopSpriteOne(blackBishopTexture);
    //sf::Sprite blackBishopSpriteTwo(blackBishopTexture);

    //// ------------------------------------------------------------------------

    //// ------------------------------------------------------------------------
    //// White king setup:

    //// Load a texture from the assets folder, containing images of chess pieces!
    //sf::Texture whiteKingTexture;

    //// Attempt to load the image file, then print an error message if the image
    //// could not be loaded correctly!
    //// "../" moves up one file directory becasuethe executable runs inside
    //// a nested project folder!
    //if (!whiteKingTexture.loadFromFile("../assets/white_king_scaled.png"))
    //{
    //    cout << "Error: failed to load assets/white_king_scaled.png" << endl;
    //    return -1;
    //}
    //// Since there was no failure with loading the image file, show a success debug message!
    //cout << "Success: Texture loaded correctly!" << endl;

    //// Create a sprite that will use the successfully loaded texture.
    //// A sprite is the 2D object that gets drawn and displayed on the screen!
    //sf::Sprite whiteKingSprite(whiteKingTexture);

    //// ------------------------------------------------------------------------

    //// ------------------------------------------------------------------------
    //// Black king setup:

    //// Load a texture from the assets folder, containing images of chess pieces!
    //sf::Texture blackKingTexture;

    //// Attempt to load the image file, then print an error message if the image
    //// could not be loaded correctly!
    //// "../" moves up one file directory becasuethe executable runs inside
    //// a nested project folder!
    //if (!blackKingTexture.loadFromFile("../assets/black_king_scaled.png"))
    //{
    //    cout << "Error: failed to load assets/black_rook_scaled.png" << endl;
    //    return -1;
    //}
    //// Since there was no failure with loading the image file, show a success debug message!
    //cout << "Success: Texture loaded correctly!" << endl;

    //// Create a sprite that will use the successfully loaded texture.
    //// A sprite is the 2D object that gets drawn and displayed on the screen!
    //sf::Sprite blackKingSprite(blackKingTexture);

    //// ------------------------------------------------------------------------

    //// ------------------------------------------------------------------------
    //// White queen setup:

    //// Load a texture from the assets folder, containing images of chess pieces!
    //sf::Texture whiteQueenTexture;

    //// Attempt to load the image file, then print an error message if the image
    //// could not be loaded correctly!
    //// "../" moves up one file directory becasuethe executable runs inside
    //// a nested project folder!
    //if (!whiteQueenTexture.loadFromFile("../assets/white_queen_scaled.png"))
    //{
    //    cout << "Error: failed to load assets/white_queen_scaled.png" << endl;
    //    return -1;
    //}
    //// Since there was no failure with loading the image file, show a success debug message!
    //cout << "Success: Texture loaded correctly!" << endl;

    //// Create a sprite that will use the successfully loaded texture.
    //// A sprite is the 2D object that gets drawn and displayed on the screen!
    //sf::Sprite whiteQueenSprite(whiteQueenTexture);

    //// ------------------------------------------------------------------------

    //// ------------------------------------------------------------------------
    //// Black queen setup:

    //// Load a texture from the assets folder, containing images of chess pieces!
    //sf::Texture blackQueenTexture;

    //// Attempt to load the image file, then print an error message if the image
    //// could not be loaded correctly!
    //// "../" moves up one file directory becasuethe executable runs inside
    //// a nested project folder!
    //if (!blackQueenTexture.loadFromFile("../assets/black_queen_scaled.png"))
    //{
    //    cout << "Error: failed to load assets/black_rook_scaled.png" << endl;
    //    return -1;
    //}
    //// Since there was no failure with loading the image file, show a success debug message!
    //cout << "Success: Texture loaded correctly!" << endl;

    //// Create a sprite that will use the successfully loaded texture.
    //// A sprite is the 2D object that gets drawn and displayed on the screen!
    //sf::Sprite blackQueenSprite(blackQueenTexture);

    //// ------------------------------------------------------------------------

    //// ------------------------------------------------------------------------

    //// Setting all sprite positions!
    //// The SFML library represents (0,0) as the top left pixel!

    //whitePawnSpriteOne.setPosition(sf::Vector2f(0.f, 600.0f));
    //whitePawnSpriteTwo.setPosition(sf::Vector2f(100.0f, 600.0f));
    //whitePawnSpriteThree.setPosition(sf::Vector2f(200.0f, 600.0f));
    //whitePawnSpriteFour.setPosition(sf::Vector2f(300.0f, 600.0f));
    //whitePawnSpriteFive.setPosition(sf::Vector2f(400.0f, 600.0f));
    //whitePawnSpriteSix.setPosition(sf::Vector2f(500.0f, 600.0f));
    //whitePawnSpriteSeven.setPosition(sf::Vector2f(600.0f, 600.0f));
    //whitePawnSpriteEight.setPosition(sf::Vector2f(700.0f, 600.0f));

    //blackPawnSpriteOne.setPosition(sf::Vector2f(0.f, 100.0f));
    //blackPawnSpriteTwo.setPosition(sf::Vector2f(100.0f, 100.0f));
    //blackPawnSpriteThree.setPosition(sf::Vector2f(200.0f, 100.0f));
    //blackPawnSpriteFour.setPosition(sf::Vector2f(300.0f, 100.0f));
    //blackPawnSpriteFive.setPosition(sf::Vector2f(400.0f, 100.0f));
    //blackPawnSpriteSix.setPosition(sf::Vector2f(500.0f, 100.0f));
    //blackPawnSpriteSeven.setPosition(sf::Vector2f(600.0f, 100.0f));
    //blackPawnSpriteEight.setPosition(sf::Vector2f(700.0f, 100.0f));

    //whiteRookSpriteOne.setPosition(sf::Vector2f(0.f, 700.0f));
    //whiteRookSpriteTwo.setPosition(sf::Vector2f(700.0f, 700.0f));

    //blackRookSpriteOne.setPosition(sf::Vector2f(0.f, 0.f));
    //blackRookSpriteTwo.setPosition(sf::Vector2(700.0f, 0.0f));

    //whiteKnightSpriteOne.setPosition(sf::Vector2f(100.0f, 700.0f));
    //whiteKnightSpriteTwo.setPosition(sf::Vector2f(600.0f, 700.0f));

    //blackKnightSpriteOne.setPosition(sf::Vector2f(100.0f, 0.f));
    //blackKnightSpriteTwo.setPosition(sf::Vector2f(600.0f, 0.f));

    //whiteBishopSpriteOne.setPosition(sf::Vector2f(200.0f, 700.0f));
    //whiteBishopSpriteTwo.setPosition(sf::Vector2f(500.0f, 700.0f));

    //blackBishopSpriteOne.setPosition(sf::Vector2f(200.0f, 0.f));
    //blackBishopSpriteTwo.setPosition(sf::Vector2f(500.0f, 0.f));

    //whiteKingSprite.setPosition(sf::Vector2f(400.0f, 700.0f));

    //blackKingSprite.setPosition(sf::Vector2f(400.0f, 0.f));

    //whiteQueenSprite.setPosition(sf::Vector2f(300.0f, 700.0f));

    //blackQueenSprite.setPosition(sf::Vector2f(300.0f, 0.f));

    //// ------------------------------------------------------------------------

    //// ------------------------------------------------------------------------

    //// Set width and height for each piece!
    //
    //// Get the original width and height of the white pawn texture!
    //float whitePawnTextureWidth = static_cast<float>(whitePawnTexture.getSize().x);
    //float whitePawntextureHeight = static_cast<float>(whitePawnTexture.getSize().y);

    //// Compute scale factors for both dimensions!
    //float whitePawnScaleX = 100.0f / whitePawnTextureWidth;
    //float whitePawnScaleY = 100.0f / whitePawntextureHeight;

    //// Choose a smaller scale inside a 100x100 window to preserve the 
    //// original image's aspect ratio, preventing the image from appearing
    //// stretched or squished!
    //float whitePawnUniformScale = min(whitePawnScaleX, whitePawnScaleY);

    //// Apply the same small scale to both axes to preserve the image's
    //// original aspect ratio!
    //whitePawnSpriteOne.setScale(sf::Vector2f(whitePawnUniformScale, whitePawnUniformScale));
    //whitePawnSpriteTwo.setScale(sf::Vector2f(whitePawnUniformScale, whitePawnUniformScale));
    //whitePawnSpriteThree.setScale(sf::Vector2f(whitePawnUniformScale, whitePawnUniformScale));
    //whitePawnSpriteFour.setScale(sf::Vector2f(whitePawnUniformScale, whitePawnUniformScale));
    //whitePawnSpriteFive.setScale(sf::Vector2f(whitePawnUniformScale, whitePawnUniformScale));
    //whitePawnSpriteSix.setScale(sf::Vector2f(whitePawnUniformScale, whitePawnUniformScale));
    //whitePawnSpriteSeven.setScale(sf::Vector2f(whitePawnUniformScale, whitePawnUniformScale));
    //whitePawnSpriteEight.setScale(sf::Vector2f(whitePawnUniformScale, whitePawnUniformScale));
    //
    //// ------------------------------------------------------------------------

    //// ------------------------------------------------------------------------
    //
    //// Get the original width and height of the black pawn texture!
    //float blackPawnTextureWidth = static_cast<float>(blackPawnTexture.getSize().x);
    //float blackPawntextureHeight = static_cast<float>(blackPawnTexture.getSize().y);

    //// Compute scale factors for both dimensions!
    //float blackPawnScaleX = 100.0f / blackPawnTextureWidth;
    //float blackPawnScaleY = 100.0f / blackPawntextureHeight;

    //// Choose a smaller scale inside a 100x100 window to preserve the 
    //// original image's aspect ratio, preventing the image from appearing
    //// stretched or squished!
    //float blackPawnUniformScale = min(blackPawnScaleX, blackPawnScaleY);

    //// Apply the same small scale to both axes to preserve the image's
    //// original aspect ratio!
    //blackPawnSpriteOne.setScale(sf::Vector2f(blackPawnUniformScale, blackPawnUniformScale));
    //blackPawnSpriteTwo.setScale(sf::Vector2f(blackPawnUniformScale, blackPawnUniformScale));
    //blackPawnSpriteThree.setScale(sf::Vector2f(blackPawnUniformScale, blackPawnUniformScale));
    //blackPawnSpriteFour.setScale(sf::Vector2f(blackPawnUniformScale, blackPawnUniformScale));
    //blackPawnSpriteFive.setScale(sf::Vector2f(blackPawnUniformScale, blackPawnUniformScale));
    //blackPawnSpriteSix.setScale(sf::Vector2f(blackPawnUniformScale, blackPawnUniformScale));
    //blackPawnSpriteSeven.setScale(sf::Vector2f(blackPawnUniformScale, blackPawnUniformScale));
    //blackPawnSpriteEight.setScale(sf::Vector2f(blackPawnUniformScale, blackPawnUniformScale));

    //// ------------------------------------------------------------------------

    //// ------------------------------------------------------------------------

    //// Get the original width and height of the white rook texture!
    //float whiteRookTextureWidth = static_cast<float>(whiteRookTexture.getSize().x);
    //float whiteRooktextureHeight = static_cast<float>(whiteRookTexture.getSize().y);

    //// Compute scale factors for both dimensions!
    //float whiteRookScaleX = 100.0f / whiteRookTextureWidth;
    //float whiteRookScaleY = 100.0f / whiteRooktextureHeight;

    //// Choose a smaller scale inside a 100x100 window to preserve the 
    //// original image's aspect ratio, preventing the image from appearing
    //// stretched or squished!
    //float whiteRookUniformScale = min(whiteRookScaleX, whiteRookScaleY);

    //// Apply the same small scale to both axes to preserve the image's
    //// original aspect ratio!
    //whiteRookSpriteOne.setScale(sf::Vector2f(whiteRookUniformScale, whiteRookUniformScale));
    //whiteRookSpriteTwo.setScale(sf::Vector2f(whiteRookUniformScale, whiteRookUniformScale));

    //// ------------------------------------------------------------------------

    //// ------------------------------------------------------------------------

    //// Get the original width and height of the black rook texture!
    //float blackRookTextureWidth = static_cast<float>(blackRookTexture.getSize().x);
    //float blackRooktextureHeight = static_cast<float>(blackRookTexture.getSize().y);

    //// Compute scale factors for both dimensions!
    //float blackRookScaleX = 100.0f / blackRookTextureWidth;
    //float blackRookScaleY = 100.0f / blackRooktextureHeight;

    //// Choose a smaller scale inside a 100x100 window to preserve the 
    //// original image's aspect ratio, preventing the image from appearing
    //// stretched or squished!
    //float blackRookUniformScale = min(blackRookScaleX, blackRookScaleY);

    //// Apply the same small scale to both axes to preserve the image's
    //// original aspect ratio!
    //blackRookSpriteOne.setScale(sf::Vector2f(blackRookUniformScale, blackRookUniformScale));
    //blackRookSpriteTwo.setScale(sf::Vector2f(blackRookUniformScale, blackRookUniformScale));

    //// ------------------------------------------------------------------------

    //// ------------------------------------------------------------------------

    //// Get the original width and height of the white knight texture!
    //float whiteKnightTextureWidth = static_cast<float>(whiteKnightTexture.getSize().x);
    //float whiteKnightTextureHeight = static_cast<float>(whiteKnightTexture.getSize().y);

    //// Compute scale factors for both dimensions!
    //float whiteKnightScaleX = 100.0f / whiteKnightTextureWidth;
    //float whiteKnightScaleY = 100.0f / whiteKnightTextureHeight;

    //// Choose a smaller scale inside a 100x100 window to preserve the 
    //// original image's aspect ratio, preventing the image from appearing
    //// stretched or squished!
    //float whiteKnightUniformScale = min(whiteKnightScaleX, whiteKnightScaleY);

    //// Apply the same small scale to both axes to preserve the image's
    //// original aspect ratio!
    //whiteKnightSpriteOne.setScale(sf::Vector2f(whiteKnightUniformScale, whiteKnightUniformScale));
    //whiteKnightSpriteTwo.setScale(sf::Vector2f(whiteKnightUniformScale, whiteKnightUniformScale));

    //// ------------------------------------------------------------------------

    //// ------------------------------------------------------------------------

    //// Get the original width and height of the black knight texture!
    //float blackKnightTextureWidth = static_cast<float>(blackKnightTexture.getSize().x);
    //float blackKnightTextureHeight = static_cast<float>(blackKnightTexture.getSize().y);

    //// Compute scale factors for both dimensions!
    //float blackKnightScaleX = 100.0f / blackKnightTextureWidth;
    //float blackKnightScaleY = 100.0f / blackKnightTextureHeight;

    //// Choose a smaller scale inside a 100x100 window to preserve the 
    //// original image's aspect ratio, preventing the image from appearing
    //// stretched or squished!
    //float blackKnightUniformScale = min(blackKnightScaleX, blackKnightScaleY);

    //// Apply the same small scale to both axes to preserve the image's
    //// original aspect ratio!
    //blackKnightSpriteOne.setScale(sf::Vector2f(blackKnightUniformScale, blackKnightUniformScale));
    //blackKnightSpriteTwo.setScale(sf::Vector2f(blackKnightUniformScale, blackKnightUniformScale));

    //// ------------------------------------------------------------------------

    //// ------------------------------------------------------------------------

    //// Get the original width and height of the white bishop texture!
    //float whiteBishopTextureWidth = static_cast<float>(whiteBishopTexture.getSize().x);
    //float whiteBishopTextureHeight = static_cast<float>(whiteBishopTexture.getSize().y);

    //// Compute scale factors for both dimensions!
    //float whiteBishopScaleX = 100.0f / whiteBishopTextureWidth;
    //float whiteBishopScaleY = 100.0f / whiteBishopTextureHeight;

    //// Choose a smaller scale inside a 100x100 window to preserve the 
    //// original image's aspect ratio, preventing the image from appearing
    //// stretched or squished!
    //float whiteBishopUniformScale = min(whiteBishopScaleX, whiteBishopScaleY);

    //// Apply the same small scale to both axes to preserve the image's
    //// original aspect ratio!
    //whiteBishopSpriteOne.setScale(sf::Vector2f(whiteBishopUniformScale, whiteBishopUniformScale));
    //whiteBishopSpriteTwo.setScale(sf::Vector2f(whiteBishopUniformScale, whiteBishopUniformScale));

    //// ------------------------------------------------------------------------

    //// ------------------------------------------------------------------------

    //// Get the original width and height of the black bishop texture!
    //float blackBishopTextureWidth = static_cast<float>(blackBishopTexture.getSize().x);
    //float blackBishopTextureHeight = static_cast<float>(blackBishopTexture.getSize().y);

    //// Compute scale factors for both dimensions!
    //float blackBishopScaleX = 100.0f / blackBishopTextureWidth;
    //float blackBishopScaleY = 100.0f / blackBishopTextureHeight;

    //// Choose a smaller scale inside a 100x100 window to preserve the 
    //// original image's aspect ratio, preventing the image from appearing
    //// stretched or squished!
    //float blackBishopUniformScale = min(blackBishopScaleX, blackBishopScaleY);

    //// Apply the same small scale to both axes to preserve the image's
    //// original aspect ratio!
    //blackBishopSpriteOne.setScale(sf::Vector2f(blackBishopUniformScale, blackBishopUniformScale));
    //blackBishopSpriteTwo.setScale(sf::Vector2f(blackBishopUniformScale, blackBishopUniformScale));

    //// ------------------------------------------------------------------------

    //// ------------------------------------------------------------------------

    //// Get the original width and height of the white king texture!
    //float whiteKingTextureWidth = static_cast<float>(whiteKingTexture.getSize().x);
    //float whiteKingTextureHeight = static_cast<float>(whiteKingTexture.getSize().y);

    //// Compute scale factors for both dimensions!
    //float whiteKingScaleX = 100.0f / whiteKingTextureWidth;
    //float whiteKingScaleY = 100.0f / whiteKingTextureHeight;

    //// Choose a smaller scale inside a 100x100 window to preserve the 
    //// original image's aspect ratio, preventing the image from appearing
    //// stretched or squished!
    //float whiteKingUniformScale = min(whiteKingScaleX, whiteKingScaleY);

    //// Apply the same small scale to both axes to preserve the image's
    //// original aspect ratio!
    //whiteKingSprite.setScale(sf::Vector2f(whiteKingUniformScale, whiteKingUniformScale));

    //// ------------------------------------------------------------------------

    //// ------------------------------------------------------------------------

    //// Get the original width and height of the black king texture!
    //float blackKingTextureWidth = static_cast<float>(blackKingTexture.getSize().x);
    //float blackKingTextureHeight = static_cast<float>(blackKingTexture.getSize().y);

    //// Compute scale factors for both dimensions!
    //float blackKingScaleX = 100.0f / blackKingTextureWidth;
    //float blackKingScaleY = 100.0f / blackKingTextureHeight;

    //// Choose a smaller scale inside a 100x100 window to preserve the 
    //// original image's aspect ratio, preventing the image from appearing
    //// stretched or squished!
    //float blackKingUniformScale = min(blackKingScaleX, blackKingScaleY);

    //// Apply the same small scale to both axes to preserve the image's
    //// original aspect ratio!
    //blackKingSprite.setScale(sf::Vector2f(blackKingUniformScale, blackKingUniformScale));

    //// ------------------------------------------------------------------------

    //// ------------------------------------------------------------------------

    //// Get the original width and height of the white queen texture!
    //float whiteQueenTextureWidth = static_cast<float>(whiteQueenTexture.getSize().x);
    //float whiteQueenTextureHeight = static_cast<float>(whiteQueenTexture.getSize().y);

    //// Compute scale factors for both dimensions!
    //float whiteQueenScaleX = 100.0f / whiteQueenTextureWidth;
    //float whiteQueenScaleY = 100.0f / whiteQueenTextureHeight;

    //// Choose a smaller scale inside a 100x100 window to preserve the 
    //// original image's aspect ratio, preventing the image from appearing
    //// stretched or squished!
    //float whiteQueenUniformScale = min(whiteQueenScaleX, whiteQueenScaleY);

    //// Apply the same small scale to both axes to preserve the image's
    //// original aspect ratio!
    //whiteQueenSprite.setScale(sf::Vector2f(whiteQueenUniformScale, whiteQueenUniformScale));

    //// ------------------------------------------------------------------------

    //// ------------------------------------------------------------------------

    //// Get the original width and height of the black queen texture!
    //float blackQueenTextureWidth = static_cast<float>(blackQueenTexture.getSize().x);
    //float blackQueenTextureHeight = static_cast<float>(blackQueenTexture.getSize().y);

    //// Compute scale factors for both dimensions!
    //float blackQueenScaleX = 100.0f / blackQueenTextureWidth;
    //float blackQueenScaleY = 100.0f / blackQueenTextureHeight;

    //// Choose a smaller scale inside a 100x100 window to preserve the 
    //// original image's aspect ratio, preventing the image from appearing
    //// stretched or squished!
    //float blackQueenUniformScale = min(blackQueenScaleX, blackQueenScaleY);

    //// Apply the same small scale to both axes to preserve the image's
    //// original aspect ratio!
    //blackQueenSprite.setScale(sf::Vector2f(blackQueenUniformScale, blackQueenUniformScale));

    //// ------------------------------------------------------------------------

    //// Existing test shape (keeping this code for now, to confirm that an image
    //// is properly displayed on the screen)!
    //sf::CircleShape shape(100.f);
    //shape.setFillColor(sf::Color::Green);

//window.draw(whitePawnSpriteOne);
        //window.draw(whitePawnSpriteTwo);
        //window.draw(whitePawnSpriteThree);
        //window.draw(whitePawnSpriteFour);
        //window.draw(whitePawnSpriteFive);
        //window.draw(whitePawnSpriteSix);
        //window.draw(whitePawnSpriteSeven);
        //window.draw(whitePawnSpriteEight);

        //// Draw the black pawn chess piece sprites!
        //window.draw(blackPawnSpriteOne);
        //window.draw(blackPawnSpriteTwo);
        //window.draw(blackPawnSpriteThree);
        //window.draw(blackPawnSpriteFour);
        //window.draw(blackPawnSpriteFive);
        //window.draw(blackPawnSpriteSix);
        //window.draw(blackPawnSpriteSeven);
        //window.draw(blackPawnSpriteEight);

        //// Draw the white rook chess piece sprites!
        //window.draw(whiteRookSpriteOne);
        //window.draw(whiteRookSpriteTwo);

        //// Draw the black rook chess piece sprites!
        //window.draw(blackRookSpriteOne);
        //window.draw(blackRookSpriteTwo);

        //// Draw the white knight chess piece sprites!
        //window.draw(whiteKnightSpriteOne);
        //window.draw(whiteKnightSpriteTwo);

        //// Draw the black knight chess piece sprites!
        //window.draw(blackKnightSpriteOne);
        //window.draw(blackKnightSpriteTwo);

        //// Draw the white bishop chess piece sprites!
        //window.draw(whiteBishopSpriteOne);
        //window.draw(whiteBishopSpriteTwo);

        //// Draw the black bishop chess piece sprites!
        //window.draw(blackBishopSpriteOne);
        //window.draw(blackBishopSpriteTwo);

        //// Draw the white king chess piece sprites!
        //window.draw(whiteKingSprite);

        //// Draw the black king chess piece sprite!
        //window.draw(blackKingSprite);

        //// Draw the white queen chess piece sprite!
        //window.draw(whiteQueenSprite);

        //// Draw the black queen chess piece sprite!
        //window.draw(blackQueenSprite);

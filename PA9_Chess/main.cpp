#include "SFML/Graphics.hpp"
#include "Menu.hpp"



int main(void) {
    

    sf::RenderWindow window(sf::VideoMode({ 1920u, 1080u }), "Chess");
    Menu menu;

    MenuResult result = menu.handleInput(window);

    if (result == MenuResult::Play) {
        // start the game
    }
    else {
        window.close();
    }
}
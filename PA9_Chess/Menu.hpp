//The menu class that is used by GameManager
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

//this class can be expanded with more menu options. 0 = Play, 1 = Quit
enum class MenuResult { Play, Quit };

class Menu {
private:
    sf::Font font;
    sf::Text titleText;

    struct Button {
        sf::RectangleShape shape; //shape and size of button
        sf::Text label; //text saying what button does
        sf::Text ButtonInput; // text saying what button to press
        MenuResult result; //what activating the button will do
        sf::Keyboard::Key hotkey; //key press to activate button
    };

    std::vector<Button> buttons;

    sf::RectangleShape background;

    //helper function to make buttons
    void addButton(const std::string& label, const std::string& InputText, MenuResult  result, sf::Keyboard::Key key, float yPos) {
        Button btn{
       sf::RectangleShape{},
       sf::Text{font, label, 32},      
       sf::Text{font, InputText, 20},     
       result,
       key
        };

        btn.shape.setSize(sf::Vector2f(400.f, 80.f));
        btn.shape.setPosition(sf::Vector2f(760.f, yPos));   // (1920 - 400) / 2
        btn.shape.setFillColor(sf::Color(70, 70, 70)); //grey 

        btn.label.setFillColor(sf::Color::White);
        btn.label.setPosition(sf::Vector2f(780.f, yPos + 20.f));

        btn.ButtonInput.setFillColor(sf::Color(180, 180, 180));
        btn.ButtonInput.setPosition(sf::Vector2f(1020.f, yPos + 28.f));

        buttons.push_back(std::move(btn)); //adds to button vector 
    }

public:
	
    Menu() : titleText(font, "Chess", 64) {
        if (!font.openFromFile("RobotoRegular.ttf")) {
            throw std::runtime_error("Failed to load font: RobotoRegular.ttf");
        }

        titleText.setFillColor(sf::Color::White);
        titleText.setPosition(sf::Vector2f(860.f, 200.f)); //centered is 960, being to the left should let it have room to be mostly centered

        background.setSize(sf::Vector2f(1920.f, 1080.f));
        background.setFillColor(sf::Color(30, 30, 30));

        addButton("Play", "Press Enter", MenuResult::Play, sf::Keyboard::Key::Enter, 450.f);
        addButton("Quit", "Press Escape", MenuResult::Quit, sf::Keyboard::Key::Escape, 570.f);
    }
        
    void draw(sf::RenderWindow& window) {
        window.draw(background);
        window.draw(titleText);
        for (auto& btn : buttons) {
            window.draw(btn.shape);
            window.draw(btn.label);
            window.draw(btn.ButtonInput);
        }
    }

    MenuResult handleInput(sf::RenderWindow& window) {
        while (window.isOpen()) {
            while (auto event = window.pollEvent()) {
                if (event->is<sf::Event::Closed>())
                    window.close();

                if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                    for (auto& btn : buttons) {
                        if (keyPressed->code == btn.hotkey)
                            return btn.result;
                    }
                }
            }
            window.clear();
            draw(window);
            window.display();
        }
        return MenuResult::Quit;
    }
    
     
};
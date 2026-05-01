#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

enum class MenuResult { Play, Multiplayer, Quit };

class Menu {
private:
    sf::Font font;
    sf::Text titleText;

    struct Button {
        sf::RectangleShape shape;
        sf::Text label;
        sf::Text ButtonInput;
        MenuResult result;
        sf::Keyboard::Key hotkey;
    };

    std::vector<Button> buttons;
    sf::RectangleShape background;

    void addButton(const std::string& label, const std::string& InputText,
        MenuResult result, sf::Keyboard::Key key, float yPos)
    {
        Button btn{
            sf::RectangleShape{},
            sf::Text{font, label, 32},
            sf::Text{font, InputText, 20},
            result,
            key
        };

        btn.shape.setSize(sf::Vector2f(400.f, 80.f));
        btn.shape.setPosition(sf::Vector2f(760.f, yPos));
        btn.shape.setFillColor(sf::Color(70, 70, 70));

        btn.label.setFillColor(sf::Color::White);
        btn.label.setPosition(sf::Vector2f(780.f, yPos + 20.f));

        btn.ButtonInput.setFillColor(sf::Color(180, 180, 180));
        btn.ButtonInput.setPosition(sf::Vector2f(1020.f, yPos + 28.f));

        buttons.push_back(std::move(btn));
    }

public:

    Menu() : titleText(font, "Chess", 64)
    {
        if (!font.openFromFile("RobotoRegular.ttf")) {
            throw std::runtime_error("Failed to load font: RobotoRegular.ttf");
        }

        titleText.setFillColor(sf::Color::White);
        titleText.setPosition(sf::Vector2f(860.f, 200.f));

        background.setSize(sf::Vector2f(1920.f, 1080.f));
        background.setFillColor(sf::Color(30, 30, 30));
		//new code for multiplayer button
        addButton("Play", "Press Enter", MenuResult::Play, sf::Keyboard::Key::Enter, 450.f);
        addButton("Multiplayer", "Press M", MenuResult::Multiplayer, sf::Keyboard::Key::M, 570.f);
        addButton("Quit", "Press Escape", MenuResult::Quit, sf::Keyboard::Key::Escape, 690.f);
    }

    void draw(sf::RenderWindow& window)
    {
        window.draw(background);
        window.draw(titleText);

        for (auto& btn : buttons) {
            window.draw(btn.shape);
            window.draw(btn.label);
            window.draw(btn.ButtonInput);
        }
    }

    MenuResult handleInput(sf::RenderWindow& window)
    {
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
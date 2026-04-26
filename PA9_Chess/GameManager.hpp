//this file will contain the class gamemanager, this class creates the menu, and will call other functions to run the game.
#include <SFML/Graphics.hpp>

class GameManager {
private:
	//the game manager will store things from the other classes, since those are not done yet I will add them later.
	sf::RenderWindow window;
	int turn; //0 for white, 1 for black

public:

	//constructor, will contain more once the other constructors are complete
	GameManager() : window(sf::VideoMode({ 1920, 1080 }), "Chess"), turn(0) {}
	
	

};
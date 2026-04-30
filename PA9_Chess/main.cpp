#include "GameManager.hpp"
#include "Test.hpp"


int main(void) {
	GameManager game;
	game.StartGame();

	Test test;
	test.runAllTests();
}

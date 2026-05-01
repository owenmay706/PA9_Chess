#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "dnsapi.lib")
#pragma comment(lib, "mbedtls.lib")
#pragma comment(lib, "mbedx509.lib")
#pragma comment(lib, "mbedcrypto.lib")
#pragma comment(lib, "bcrypt.lib") 
#pragma comment(lib, "crypt32.lib") 

#include "GameManager.hpp"
#include "Test.hpp"

int main(void) {
	GameManager game;
	game.StartGame();

	Test test;
	test.runAllTests();
}
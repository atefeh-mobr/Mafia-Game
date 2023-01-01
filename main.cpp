#include <iostream>
#include <vector>
#include "game.hpp"

using namespace std;

const string CREATE_GAME = "create_game";
const string ASSIGN_ROLE = "assign_role";
const string START_GAME = "start_game";
const string GET_GAME_STATE = "get_game_state";
const int REATE_GAME_SIZE = 11;
const int ASSIGN_ROLE_SIZE = 11;
const int START_GAME_SIZE = 10;
const int GET_GAME_STATE_SIZE = 14;

int main() {
	string order;
	Game *game = new Game();
	while(getline(cin, order)) {
		if(order.substr(0, REATE_GAME_SIZE) == CREATE_GAME) {
			game = new Game(1);
			game->createGame(order.substr(REATE_GAME_SIZE + 1));
		}
		else if(order.substr(0, ASSIGN_ROLE_SIZE) == ASSIGN_ROLE)
			game->assignRole(order.substr(ASSIGN_ROLE_SIZE + 1));
		else if(order.substr(0, START_GAME_SIZE) == START_GAME)
			game->checkToStart();
		else if(order.substr(0, GET_GAME_STATE_SIZE) == GET_GAME_STATE)
			game->getGameState();
	}
	delete game;
	return 0;
}
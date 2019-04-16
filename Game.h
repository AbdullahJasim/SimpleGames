#pragma once

#ifndef GAME
#define GAME

#include "Deck.h"
#include "Player.h"
#include "House.h"

class Game {
public:
	Game(const vector<string>& names);
	~Game();
	void Play();

private:
	Deck m_Deck;
	House m_House;
	vector<Player> m_Players;
};

#endif
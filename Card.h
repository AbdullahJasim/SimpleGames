#pragma once

#ifndef CARD
#define CARD

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

class Card {
public:
	enum rank {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, 
				EIGHT, NINE, TEN, JACK, QUEEN, KING};
	enum suit {CLUBS, DIAMONDS, HEARTS, SPADES};

	friend ostream& operator<<(ostream& os, const Card& aCard);

	Card(rank r = ACE, suit S = SPADES, bool ifu = true);
	int GetValue() const;
	void Flip();

private:
	rank m_Rank;
	suit m_Suit;
	bool m_IsFaceUp;
};

#endif
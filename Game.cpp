#include "Game.h"

Game::Game(const vector<string>& names) {
	vector<string>::const_iterator pName;

	for (pName = names.begin(); pName != names.end(); ++pName) m_Players.push_back(Player(*pName));

	srand(static_cast<unsigned int>(time(0)));
	m_Deck.Populate();
	m_Deck.Shuffle();
}

Game::~Game() {}

void Game::Play() {
	vector<Player>::iterator pPlayer;

	for (int i = 0; i < 2; ++i) {
		for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer) m_Deck.Deal(*pPlayer);
		m_Deck.Deal(m_House);
	}

	m_House.FlipFirstCard();

	for (int i = 0; i < 2; ++i) for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer) cout << *pPlayer << endl;
	cout << m_House << endl;

	for (int i = 0; i < 2; ++i) for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer) m_Deck.AdditionalCards(*pPlayer);

	m_House.FlipFirstCard();
	cout << endl << m_House;

	m_Deck.AdditionalCards(m_House);

	if (m_House.IsBusted()) {
		for (int i = 0; i < 2; ++i) for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer) {
			if (!pPlayer->IsBusted()) pPlayer->Win();
		}
	} else {
		for (int i = 0; i < 2; ++i) for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer) {
			if (!pPlayer->IsBusted()) {
				if (pPlayer->GetTotal() > m_House.GetTotal()) {
					pPlayer->Win();
				} else {
					pPlayer->Lose();
				}
			} else {
				pPlayer->Push();
			}
		}
	}

	for (int i = 0; i < 2; ++i) for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer) {
		pPlayer->Clear();
	}

	m_House.Clear();
}

ostream& operator<<(ostream& os, const Card& aCard);
ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer);

int main() {
	cout << "Welcome to this round of Black Jack!\n";

	int numPlayers = 0;

	while (numPlayers < 1 || numPlayers > 7) {
		cout << "How many players will be playing? (1-7): ";
		cin >> numPlayers;
	}

	vector<string> names;
	string name;

	for (int i = 0; i < numPlayers; ++i) {
		cout << "Enter name of player: ";
		cin >> name;
		names.push_back(name);
	}

	cout << endl;

	Game aGame(names);
	char again = 'y';

	while (again != 'n' && again != 'N') {
		aGame.Play();
		cout << "Do you want to play again? (Y/N)\n";
		cin >> again;
	}

	return 0;
}

ostream& operator<<(ostream& os, const Card& aCard) {
	const string RANKS[] = {"0", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
	const string SUITS[] = {"C", "D", "H", "S"};

	if (aCard.m_IsFaceUp) {
		os << RANKS[aCard.m_Rank] << SUITS[aCard.m_Suit];
	} else {
		os << "XX";
	}

	return os;
}

ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer) {
	os << aGenericPlayer.m_Name << ":\t";

	vector<Card*>::const_iterator pCard;

	if (!aGenericPlayer.m_Cards.empty()) {
		for (pCard = aGenericPlayer.m_Cards.begin(); pCard != aGenericPlayer.m_Cards.end(); ++pCard) {
			os << *(*pCard) << "\t";
		}

		if (aGenericPlayer.GetTotal() != 0) {
			cout << "(" << aGenericPlayer.GetTotal() << ")";
		}
	} else {
		os << "<empty>";
	}

	return os;
}
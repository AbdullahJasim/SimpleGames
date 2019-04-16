#include "House.h"

House::House(const string& name) :
	GenericPlayer(name)
{}

House::~House() {}

bool House::IsHitting() const {
	return (GetTotal() <= 16);
}

void House::FlipFirstCard() {
	if (m_Cards.empty()) {
		cout << "No cards to flip.\n";
		return;
	}

	m_Cards[0]->Flip();
}
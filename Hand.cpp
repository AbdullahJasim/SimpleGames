#include "Hand.h"

Hand::Hand() {
	m_Cards.reserve(7);
}

Hand::~Hand() {
	Clear();
}

void Hand::Add(Card* pCard) {
	m_Cards.push_back(pCard);
}

void Hand::Clear() {
	vector<Card*>::iterator iter;

	for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter) {
		delete *iter;
		*iter = nullptr;
	}

	m_Cards.clear();
}

int Hand::GetTotal() const {
	if (m_Cards.empty() || m_Cards[0]->GetValue() == 0) return 0;

	int total = 0;
	bool containsAce = false;
	vector<Card*>::const_iterator iter;

	for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter) {
		total += (*iter)->GetValue();
		if ((*iter)->GetValue() == Card::ACE) containsAce = true;
	}

	if (containsAce && total <= 11) total += 10;

	return total;
}
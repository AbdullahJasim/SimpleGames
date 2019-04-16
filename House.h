#pragma once

#ifndef HOUSE
#define HOUSE

#include "GenericPlayer.h"

class House : public GenericPlayer {
public:
	House(const string& name = "House");
	virtual ~House();
	virtual bool IsHitting() const;
	void FlipFirstCard();
};

#endif
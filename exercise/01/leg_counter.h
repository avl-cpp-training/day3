#pragma once

#include <string>
#include "animal.h"

class leg_counter
{
private:
	unsigned int count;
public:
	leg_counter() : count(0) {};
	std::wstring add_animal(std::unique_ptr<animal> animal);
	unsigned int legs() const;
};


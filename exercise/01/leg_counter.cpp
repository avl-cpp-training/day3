#include "leg_counter.h"

std::wstring leg_counter::add_animal(std::unique_ptr<animal> animal)
{
	if (animal != nullptr)
	{
		count += animal->legs();
		return animal->species();
	}
	return std::wstring();
}

unsigned int leg_counter::legs() const
{
	return count;
}

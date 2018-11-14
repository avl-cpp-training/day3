#include "animal.h"

std::wstring animal::species() const
{
	return std::wstring();
}

unsigned int animal::legs() const
{
	return 0;
}

std::wstring leg_counter::add_animal(const animal & animal)
{
	return std::wstring();
}

unsigned int leg_counter::legs() const
{
	return 0;
}

animal animal_factory(int index)
{
	return animal();
}

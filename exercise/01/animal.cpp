#include "animal.h"

unsigned insect::legs() const
{
	return legCount;
}

std::wstring cockroach::species() const
{
	return speciesName;
}

unsigned bird::legs() const
{
	return legCount;

}

std::wstring sparrow::species() const
{
	return speciesName;
}

unsigned spider::legs() const
{
	return legCount;

}

std::wstring tarantula::species() const
{
	return speciesName;
}

std::wstring leg_counter::add_animal(animal* animal) const
{
	return animal->species();
}

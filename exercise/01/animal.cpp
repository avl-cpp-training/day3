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

std::wstring leg_counter::add_animal(std::unique_ptr<animal> animal)
{
	animalCount += animal->legs();
	return animal->species();
}

unsigned leg_counter::legs() const
{
	return animalCount;
}


enum Animals { Cockroach = 1, Sparrow = 2, Tarantula = 3 };

std::unique_ptr<animal> animal_factory(int num)
{
	if (num == Animals::Cockroach)
	{
		return std::make_unique<cockroach>();
	}
	if (num == Animals::Sparrow)
	{
		return std::make_unique<sparrow>();
	}
	if (num == Animals::Tarantula)
	{
		return std::make_unique<tarantula>();
	}

	return nullptr;
}
#include "animal.h"

unsigned int insect::legs() const
{
	return 6;
}

std::wstring cockroach::species() const
{
	return L"cockroach";
}

unsigned int bird::legs() const
{
	return 2;
}

std::wstring sparrow::species() const
{
	return L"sparrow";
}

unsigned int spider::legs() const
{
	return 8;
}

std::wstring tarantula::species() const
{
	return L"tarantula";
}

std::wstring leg_counter::add_animal(const animal_factory& animal_fac)
{
	auto animal = animal_fac.get_animal();
	nlegs += animal->legs();
	return animal->species();
}

unsigned int leg_counter::legs() const
{
	return nlegs;
}

animal_factory::animal_factory(unsigned int id)
{
	switch (id)
	{
	case 1:
		a = new cockroach;
		break;
	case 2:
		a = new sparrow;
		break;
	case 3:
		a = new tarantula;
		break;
	default:
		throw std::invalid_argument("Wrong id.");
	}
}

animal_factory::~animal_factory()
{
	if (!a)
		return;
	delete a;
}

animal* animal_factory::get_animal() const
{
	return a;
}

#include "animal.h"

std::wstring cockroach::species() const
{
	return L"cockroach";
}

unsigned int cockroach::legs() const
{
	return 6u;
}

cockroach::~cockroach(){ }

std::wstring sparrow::species() const
{
	return L"sparrow";
}

unsigned int sparrow::legs() const
{
	return 2u;
}

sparrow::~sparrow(){ }

std::wstring tarantula::species() const
{
	return L"tarantula";
}

unsigned int tarantula::legs() const
{
	return 8u;
}

tarantula::~tarantula() { }


animal_factory::animal_factory(int id)
{
	this->id = id;
	create_animal();
}

animal* animal_factory::create_animal() const
{
	switch (id)
	{
	case 1: return new cockroach;
		break;
	case 2: return new sparrow;
		break;
	case 3: return new tarantula;
		break;
	default: return nullptr;
		break;
	}
}

std::wstring leg_counter::add_animal(animal_factory& af)
{
	animal* a = af.create_animal();
	counter += a->legs();
	std::wstring species = a->species();
	delete a;
	return species;
}

unsigned int leg_counter::legs() const
{
	return counter;
}
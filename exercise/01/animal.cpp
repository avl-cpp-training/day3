#include "animal.h"
unsigned insect::legs()
{
	return 6u;
}

unsigned bird::legs()
{
	return 2u;
}

unsigned spider::legs()
{
	return  8u;
}

std::wstring cockroach::species()
{
	return L"cockroach";
}

std::wstring sparrow::species()
{
	return L"sparrow";
}

std::wstring tarantula::species()
{
	return  L"tarantula";
}

unsigned leg_counter::legs()
{
	unsigned int sum=0;
	std::list<animal*>::iterator itr = animals_.begin();
	for (itr = animals_.begin(); itr != animals_.end(); ++itr)
	{
		sum += (*itr)->legs();
	}
	return sum;
}

std::wstring leg_counter::add_animal(animal* animal)
{

	animals_.push_back(animal);
	return animal->species();
}

animal* animal_factory(int animal)
{
	switch (animal)
	{
	case animal_type::cockroach:
		return new cockroach{};
	case animal_type::tarantula:
		return new tarantula{};
	case animal_type::sparrow:
		return new sparrow{};
	}
}





#include "animal.h"
#include <exception>

animal::~animal() { }

const std::wstring cockroach::type = L"cockroach";

std::wstring cockroach::species() const
{
	return type;
}

unsigned int insect::legs() const
{
	return number_of_legs;
}

const std::wstring sparrow::type = L"sparrow";

std::wstring sparrow::species() const
{
	return type;
}

unsigned int bird::legs() const
{
	return number_of_legs;
}

const std::wstring tarantula::type = L"tarantula";

std::wstring tarantula::species() const
{
	return type;
}

unsigned int spider::legs() const
{
	return number_of_legs;
}

std::wstring leg_counter::add_animal(const animal_factory & factory)
{
	std::unique_ptr<animal> animal = factory.create_animal();
	number_of_legs += animal->legs();
	return animal->species();
}

unsigned int leg_counter::legs() const
{
	return number_of_legs;
}

std::unique_ptr<animal> animal_factory::create_animal() const
{
	switch (animal_num)
	{
	case 1: return std::make_unique<cockroach>();
	case 2: return std::make_unique<sparrow>();
	case 3: return std::make_unique<tarantula>();
	}
	throw std::invalid_argument("There is no animal with that number!");
}
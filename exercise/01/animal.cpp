#include "animal.h"

animal::animal() {};
animal::~animal() {};

unsigned int bird::legs() { return 2; }
std::wstring sparrow::species() { return L"sparrow"; }

unsigned int insect::legs() { return 6; }
std::wstring cockroach::species() { return  L"cockroach"; }

unsigned int spider::legs() { return 8; }
std::wstring tarantula::species() { return L"tarantula"; }

std::wstring leg_counter::add_animal(animal* a)
{
  animals.push_back(a);
  return a->species();
}

unsigned int leg_counter::legs() const
{
  unsigned int sum_of_legs = 0;
  for each (animal* a in animals)
  {
    sum_of_legs += a->legs();
  }
  return sum_of_legs;
}

animal* animal_factory(int animal_type)
{
  switch (animal_type) {
  case 1:
    return new cockroach;
  case 2:
    return new sparrow;
  case 3:
    return new tarantula;
  default: 
    return nullptr;
  }
}
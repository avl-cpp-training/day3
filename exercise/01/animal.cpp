#include "animal.h"

animal::animal() {};
animal::~animal() {};

unsigned int bird::legs() { return 2; }
std::wstring sparrow::species() { return L"sparrow"; }

unsigned int insect::legs() { return 6; }
std::wstring cockroach::species() { return  L"cockroach"; }

unsigned int spider::legs() { return 8; }
std::wstring tarantula::species() { return L"tarantula"; }

std::wstring leg_counter::add_animal(std::unique_ptr<animal> &a)
{
  std::wstring s = a->species();
  animals.push_back(std::move(a));
  return s;
}

unsigned int leg_counter::legs() const
{
  unsigned int sum_of_legs = 0;
  for each (std::unique_ptr<animal> const& a in animals)
    {
    sum_of_legs += a->legs();
  }
  return sum_of_legs;
}

std::unique_ptr<animal> animal_factory(int animal_type)
{
  switch (animal_type) {
  case 1:
    return std::make_unique<cockroach>();
  case 2:
    return std::make_unique<sparrow>();
  case 3:
    return std::make_unique<tarantula>();
  default:
    return nullptr;
  }
}
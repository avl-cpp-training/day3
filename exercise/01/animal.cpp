#include "animal.h"

unsigned int insect::legs() const
{
  return 6u;
}

std::wstring cockroach::species() const
{
  return L"cockroach";
}

unsigned bird::legs() const
{
  return 2u;
}

std::wstring sparrow::species() const
{
  return L"sparrow";
}

unsigned int spider::legs() const
{
  return 8u;
}

std::wstring tarantula::species() const
{
  return L"tarantula";
}

std::unique_ptr<animal> animal_factory(const int id)
{
  switch (id)
  {
  case cockroachId:
    return std::make_unique<cockroach>();
  case sparrowId:
    return std::make_unique<sparrow>();
  case tarantulaId:
    return std::make_unique<tarantula>();
  default:
    throw std::invalid_argument("Animal with id " + std::to_string(id) + " doesn't exist!");
  }
}

leg_counter::leg_counter() : legCount(0)
{
}

unsigned int leg_counter::legs() const
{
  return legCount;
}

std::wstring leg_counter::add_animal(const std::unique_ptr<animal> animal)
{
  legCount += animal->legs();

  return animal->species();
}


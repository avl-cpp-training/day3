#include "animal.h"

animal::animal(unsigned int legs, const wchar_t species[]) :
  legs_(legs),
  species_(species)
{}

std::wstring animal::species() const
{
  return species_;
}

unsigned animal::legs() const
{
  return legs_;
}

spider::spider(const wchar_t species[]) :
  animal(8, species)
{}

insect::insect(const wchar_t species[]) :
  animal(6, species)
{}

bird::bird(const wchar_t species[]) :
  animal(2, species)
{}

tarantula::tarantula() :
  spider(L"tarantula")
{}

cockroach::cockroach() :
  insect(L"cockroach")
{}

sparrow::sparrow() : bird(L"sparrow")
{}

animal* animal_factory(int id)
{
  switch (id) {
  case 1: return new cockroach;
  case 2: return new sparrow;
  case 3: return new tarantula;
  default: return nullptr;
  }
}

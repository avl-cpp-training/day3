#include "animal.h"

std::unique_ptr<animal> animal_factory(const anuanimal_enum id)
{
  switch (id)
  {
  case cockroach_id: return std::make_unique<cockroach>();
  case sparrow_id: return std::make_unique<sparrow>();
  case tarantula_id: return std::make_unique<tarantula>();
  }
  return {};
}

animal_base::animal_base(unsigned int legs, const std::wstring& species) :
  legs_(legs),
  species_(species)
{
}

std::wstring animal_base::species() const
{
  return species_;
}

unsigned animal_base::legs() const
{
  return legs_;
}

spider::spider(const std::wstring& species) :
  animal_base(8, species)
{}

insect::insect(const std::wstring& species) :
  animal_base(6, species)
{}

bird::bird(const std::wstring& species) :
  animal_base(2, species)
{}

tarantula::tarantula() :
  spider(L"tarantula")
{}

cockroach::cockroach() :
  insect(L"cockroach")
{}

sparrow::sparrow() : bird(L"sparrow")
{}

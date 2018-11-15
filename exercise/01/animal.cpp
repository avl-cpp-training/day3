
#include "animal.h"

unsigned int insect::legs() const
{
  return 6;
}


/////////////////////////////////////////////////////////////////////////
std::wstring cockroach::species() const
{
  return L"cockroach";
}


/////////////////////////////////////////////////////////////////////////
unsigned int bird::legs() const
{
  return 2;
}


/////////////////////////////////////////////////////////
std::wstring sparrow::species() const
{
  return L"sparrow";
}


////////////////////////////////////////////////////////
unsigned int spider::legs() const
{
  return 8;
}


////////////////////////////////////////////////////////
std::wstring tarantula::species() const
{
  return L"tarantula";
}


//////////////////////////////////////////////////////////////////////////
std::wstring leg_counter::add_animal(const std::unique_ptr<animal> NewAnimal)
{
  m_lLegCount += NewAnimal->legs();
  return NewAnimal->species();
}


const unsigned int leg_counter::legs()
{
  return m_lLegCount;
}


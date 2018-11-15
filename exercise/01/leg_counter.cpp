#include "leg_counter.h"



leg_counter::leg_counter() :
  legCount(0)
{
}


leg_counter::~leg_counter()
{
}

std::wstring leg_counter::add_animal(animal* animal)
{
  legCount += animal->legs();
  std::wstring species = animal->species();
  delete animal;
  animal = nullptr;
  return species;
}

unsigned int leg_counter::legs()
{
  return legCount;
}

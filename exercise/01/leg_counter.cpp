#include  "leg_counter.h"

leg_counter::~leg_counter()
{
  for (auto animal : anima_vector_)
    delete animal;
}

std::wstring leg_counter::add_animal(const animal* animal)
{
  if (animal == nullptr)
    return L"";
  anima_vector_.push_back(animal);
  return animal->species();
}

unsigned leg_counter::legs() const
{
  unsigned sum = 0;
  for (auto animal : anima_vector_)
    sum += animal->legs();
  return sum;
}

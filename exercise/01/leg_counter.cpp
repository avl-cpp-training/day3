#include  "leg_counter.h"

std::wstring leg_counter::add_animal(std::unique_ptr<animal> animal)
{
  if (animal == nullptr)
    return L"";
  sum_ += animal->legs();
  return animal->species();
}

unsigned leg_counter::legs() const
{
  return sum_;
}

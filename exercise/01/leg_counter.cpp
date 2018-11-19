#include  "leg_counter.h"

std::wstring leg_counter::add_animal(const std::unique_ptr<animal>& animal_ptr)
{
  if (animal_ptr == nullptr)
    return L"";
  sum_ += animal_ptr->legs();
  return animal_ptr->species();
}

unsigned leg_counter::legs() const
{
  return sum_;
}

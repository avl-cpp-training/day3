#include "animal.h"
#include <numeric>

std::wstring leg_counter::add_animal(std::unique_ptr<animal>&& animal)
{
  if (!animal)
    return std::wstring();

  animals.emplace_back(std::move(animal));
  return animals.back()->species();
}

std::size_t leg_counter::legs() const noexcept
{
  return std::accumulate(std::cbegin(animals), std::cend(animals), 0u, [](auto accu, auto const & animal) { return accu + animal->legs(); });
}

std::unique_ptr<animal> animal_factory(animal_id animal)
{
  switch (animal)
  {
  case sparrow_id: return std::make_unique<sparrow>();
  case tarantula_id: return std::make_unique<tarantula>();
  case cockroach_id: return std::make_unique <cockroach>();
  default: return nullptr;
  }
}

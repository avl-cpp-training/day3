#include  "animal.h"
#include <algorithm>

animal::~animal() = default;

namespace species
{
  enum { cockroach = 1, sparrow, tarantula };
}

unsigned insect::legs() const noexcept
{
  return 6;
}

unsigned bird::legs() const noexcept
{
  return 2;
}

unsigned spider::legs() const noexcept
{
  return 8;
}

std::wstring cockroach::species() const noexcept
{
  return L"cockroach";
}

std::wstring sparrow::species() const noexcept
{
  return L"sparrow";
}

std::wstring tarantula::species() const noexcept
{
  return L"tarantula";
}

std::wstring leg_counter::add_animal(std::unique_ptr<animal> animal)
{
  std::wstring species{animal->species()};
  animals_.push_back(std::move(animal));
  return species;
}

unsigned leg_counter::legs() const
{
  int sum{};
  std::for_each(animals_.cbegin(), animals_.cend(), [&sum](const std::unique_ptr<animal>& a) { sum += a->legs(); });
  return sum;
}

std::unique_ptr<animal> animal_factory(const int animal)
{
  switch (animal)
  {
  case species::cockroach: return std::make_unique<cockroach>(cockroach{});
  case species::sparrow: return std::make_unique<sparrow>(sparrow{});
  case species::tarantula: return std::make_unique<tarantula>(tarantula{});
  default: throw std::invalid_argument{"Unknown animal species"};
  }
}

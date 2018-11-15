#include "animal.h"
#include <numeric>

animal::~animal() = default;

std::size_t insect::legs() const noexcept
{
  return 6u;
}

std::wstring cockroach::species() const
{
  return L"cockroach";
}

std::size_t bird::legs() const noexcept
{
  return 2u;
}

std::wstring sparrow::species() const
{
  return L"sparrow";
}

std::size_t spider::legs() const noexcept
{
  return 8u;
}

std::wstring tarantula::species() const
{
  return L"tarantula";
}

std::unique_ptr<animal> animal_factory(const std::size_t animal_id)
{
  switch(animal_id)
  {
  case 1u:
    return std::make_unique<cockroach>();
  case 2u:
    return std::make_unique<sparrow>();
  case 3u:
    return std::make_unique<tarantula>();
  default:
    throw std::invalid_argument("invalid animal id");
  }
}

leg_counter::leg_counter() : num_legs(0) {}

std::size_t leg_counter::legs() const noexcept
{
  return num_legs;
}

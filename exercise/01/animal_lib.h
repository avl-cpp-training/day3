#pragma once
#include <utility>
#include <string>

struct animal
{
  virtual std::size_t legs() const noexcept = 0;
  virtual std::wstring const & species() const noexcept = 0;
  virtual ~animal() = default;
};

template<typename T, std::size_t ANIMAL_ID>
static T fail_name()
{
  static_assert(false, "specialize value member");
}

using animal_family_id = std::size_t;
template<animal_family_id ANIMAL_FAMILY_ID>
struct leg_count
{
  static const std::size_t value;
};
template<animal_family_id ANIMAL_FAMILY_ID> const std::size_t leg_count<ANIMAL_FAMILY_ID>::value = fail_name<std::size_t, ANIMAL_FAMILY_ID>();

template<animal_family_id ANIMAL_FAMILY_ID>
struct legged_animal : animal
{
  std::size_t legs() const noexcept override final
  {
    return leg_count<ANIMAL_FAMILY_ID>::value;
  }
};

using animal_id = std::size_t;
template<animal_id ANIMAL_ID>
struct animal_name
{
  static const std::wstring value;
};
template<animal_id ANIMAL_ID> const std::wstring animal_name<ANIMAL_ID>::value = fail_name<std::wstring, ANIMAL_ID>();

template<animal_id ANIMAL_ID, animal_family_id ANIMAL_FAMILY_ID>
struct named_animal final : legged_animal<ANIMAL_FAMILY_ID>
{
  std::wstring const & species() const noexcept override
  {
    return animal_name<ANIMAL_ID>::value;
  }
};
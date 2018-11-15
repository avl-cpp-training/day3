#pragma once
#include <utility>
#include <string>

struct animal
{
  virtual std::size_t legs() const noexcept = 0;
  virtual std::wstring const & species() const noexcept = 0;
  virtual ~animal() = default;
};

template<std::size_t LEGS>
struct legged_animal : animal
{
  std::size_t legs() const noexcept override final
  {
    return LEGS;
  }
};

using animal_id = std::size_t;
template<animal_id ANIMAL_ID>
struct animal_name
{
  static const std::wstring value;
};

template<animal_id ANIMAL_ID>
static std::wstring fail_name()
{
  static_assert(false, "specialize name member");
}
template<animal_id ANIMAL_ID> const std::wstring animal_name<ANIMAL_ID>::value = fail_name<ANIMAL_ID>();

template<std::size_t ANIMAL_ID, typename ANIMAL_TYPE>
struct named_animal final : ANIMAL_TYPE
{
  std::wstring const & species() const noexcept override
  {
    return animal_name<ANIMAL_ID>::value;
  }
};
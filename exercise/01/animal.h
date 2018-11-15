#pragma once
#include <utility>
#include <string>
#include <memory>
#include <vector>

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

//---------------------------------------------------------------------------------------------------------

using bird = legged_animal<2u>;
using spider = legged_animal<8u>;
using insect = legged_animal<6u>;

const animal_id cockroach_id = 1;
const animal_id sparrow_id = 2;
const animal_id tarantula_id = 3;

template<> const std::wstring animal_name<sparrow_id>::value = L"sparrow";
template<> const std::wstring animal_name<cockroach_id>::value = L"cockroach";
template<> const std::wstring animal_name<tarantula_id>::value = L"tarantula";

using sparrow = named_animal<sparrow_id, bird>;
using tarantula = named_animal<tarantula_id, spider>;
using cockroach = named_animal<cockroach_id, insect>;

std::unique_ptr<animal> animal_factory(animal_id animal);

struct leg_counter final
{
  std::wstring add_animal(std::unique_ptr<animal>&& animal);
  std::size_t legs() const noexcept;

private:
  std::vector<std::unique_ptr<animal>> animals;
};

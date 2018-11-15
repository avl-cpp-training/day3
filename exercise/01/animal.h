#pragma once
#include "animal_lib.h"
#include <string>
#include <memory>
#include <vector>

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

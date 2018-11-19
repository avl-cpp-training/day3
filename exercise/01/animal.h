#pragma once
#include "animal_lib.h"
#include <string>
#include <memory>
#include <vector>

const animal_family_id bird_id = 1;
const animal_family_id spider_id = 2;
const animal_family_id insect_id = 3;

template<> const std::size_t leg_count<bird_id>::value = 2u;
template<> const std::size_t leg_count<spider_id>::value = 8u;
template<> const std::size_t leg_count<insect_id>::value = 6u;

using bird = legged_animal<bird_id>;
using spider = legged_animal<spider_id>;
using insect = legged_animal<insect_id>;

const animal_id cockroach_id = 1;
const animal_id sparrow_id = 2;
const animal_id tarantula_id = 3;

template<> const std::wstring animal_name<sparrow_id>::value = L"sparrow";
template<> const std::wstring animal_name<cockroach_id>::value = L"cockroach";
template<> const std::wstring animal_name<tarantula_id>::value = L"tarantula";

using sparrow = named_animal<sparrow_id, bird_id>;
using tarantula = named_animal<tarantula_id, spider_id>;
using cockroach = named_animal<cockroach_id, insect_id>;

std::unique_ptr<animal> animal_factory(animal_id animal);

struct leg_counter final
{
  std::wstring add_animal(std::unique_ptr<animal>&& animal);
  std::size_t legs() const noexcept;

private:
  std::vector<std::unique_ptr<animal>> animals;
};

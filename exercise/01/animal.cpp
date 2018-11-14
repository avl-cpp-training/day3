#include "animal.h"

//---------------- Insects

unsigned int insect::legs() const {
  return 6U;
}

std::wstring cockroach::species() const {
  return L"cockroach";
}

//---------------- Birds

unsigned bird::legs() const {
  return 2U;
}

std::wstring sparrow::species() const {
  return L"sparrow";
}

//---------------- Spiders

unsigned spider::legs() const {
  return 8U;
}

std::wstring tarantula::species() const {
  return L"tarantula";
}

//---------------- leg_counter

unsigned leg_counter::legs() const {
    return legs_;
}

std::wstring leg_counter::add_animal(const std::unique_ptr<animal>& concrete_animal) {
  legs_ += concrete_animal->legs();
  return concrete_animal->species();
}

//---------------- animal_factory

std::unique_ptr<animal> animal_factory(int of_type) {
  switch (of_type) {
    case 1: return std::make_unique<cockroach>();
    case 2: return std::make_unique <sparrow>();
    case 3: return std::make_unique <tarantula>();
    default: throw std::invalid_argument("Unknown animal type");
  }
}
#include "animal.h"

#include <stdexcept>

animal::animal(std::wstring const& species, std::uint8_t legs) 
    : species_{ species }
    , legs_{legs}
{
}

animal::~animal() = default;

cockroach::cockroach() : insect(species_name, legs) {}

tarantula::tarantula() : spider(species_name, legs) {}

sparrow::sparrow() : bird(species_name, legs) {}

std::unique_ptr<animal> animal_factory(int animal_id)
{
    switch (animal_id)
    {
    case cockroach::animal_id:
        return std::make_unique<cockroach>();
    case tarantula::animal_id:
        return std::make_unique<tarantula>();
    case sparrow::animal_id:
        return std::make_unique<sparrow>();
    default:
        throw std::out_of_range("");
    }
}

std::wstring const& leg_counter::add_animal(std::unique_ptr<animal> const& ptr) noexcept
{
    legs_ += ptr->legs();
    return ptr->species();
}

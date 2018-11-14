#pragma once
#include <string>
#include <memory>

struct animal
{
  virtual ~animal();
  virtual std::wstring species() const noexcept = 0;
  virtual std::size_t legs() const noexcept = 0;
};

struct insect : animal
{
  std::size_t legs() const noexcept override;
};

struct cockroach final : insect
{
  std::wstring species() const noexcept override;
};

struct bird : animal
{
  std::size_t legs() const noexcept override;
};

struct sparrow final : bird
{
  std::wstring species() const noexcept override;
};

struct spider : animal
{
  std::size_t legs() const noexcept override;
};

struct tarantula final : spider
{
  std::wstring species() const noexcept override;
};


std::unique_ptr<animal> animal_factory(std::size_t animal_id);

struct leg_counter final
{
  leg_counter();
  template<typename AnimalPtrT>
  std::wstring add_animal(AnimalPtrT animal);
  std::size_t legs() const noexcept;

private:
  std::size_t num_legs;
};

template <typename AnimalPtrT>
std::wstring leg_counter::add_animal(AnimalPtrT animal)
{
  if (animal)
  {
    num_legs += animal->legs();
    return animal->species();
  }
  throw std::invalid_argument("invalid pointer type");
}


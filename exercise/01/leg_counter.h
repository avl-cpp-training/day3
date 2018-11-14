#pragma once
#include "animal.h"
#include <vector>

class leg_counter
{
public:
  leg_counter() = default;
  leg_counter(const leg_counter&) = delete;
  leg_counter(leg_counter&&) = delete;
  ~leg_counter();
  leg_counter& operator=(const leg_counter&) = delete;

  std::wstring add_animal(const animal* animal);
  unsigned int legs() const;

private:
  std::vector<const animal*> anima_vector_;
};

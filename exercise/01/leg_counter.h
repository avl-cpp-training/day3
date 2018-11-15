#pragma once
#include <string>
#include "animal.h"

class leg_counter
{
private:
  int legCount;
public:
  leg_counter();
  ~leg_counter();
  std::wstring add_animal(animal*);
  unsigned int legs();
};


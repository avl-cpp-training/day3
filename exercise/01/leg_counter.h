#pragma once
#include "animal.h"
#include <vector>

class leg_counter final
{
public:
  leg_counter() : sum_(0) {}
  std::wstring add_animal(const std::unique_ptr<animal>&);
  unsigned int legs() const;

private:
  int sum_;
};

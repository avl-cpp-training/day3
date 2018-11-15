#pragma once
#include "animal.h"

class bird :
  public animal
{
public:
  bird();
  ~bird();
  static const unsigned int numberOfLegs;
  unsigned int legs();
};


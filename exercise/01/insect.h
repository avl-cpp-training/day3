#pragma once
#include "animal.h"

class insect :
  public animal
{
public:
  insect();
  ~insect();
  unsigned int legs();
  static const unsigned int numberOfLegs;
};


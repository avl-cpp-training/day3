#pragma once
#include "animal.h"

class spider :
  public animal
{
private:
  static const unsigned int numberOfLegs;
public:
  spider();
  ~spider();
  unsigned int legs();
};


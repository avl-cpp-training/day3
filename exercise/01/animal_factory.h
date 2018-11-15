#pragma once

#include "cockroach.h"
#include "sparrow.h"
#include "tarantula.h"

animal* animal_factory(unsigned int type)
{
  switch (type)
  {
  case 1:
    return new cockroach;
  case 2:
    return new sparrow;
  case 3:
    return new tarantula;
  default:
    return nullptr;
  }
}

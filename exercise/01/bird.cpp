#include "bird.h"

const unsigned int bird::numberOfLegs = 2;

bird::bird()
{
}


bird::~bird()
{
}

unsigned int bird::legs()
{
  return numberOfLegs;
}

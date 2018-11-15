#include "insect.h"

const unsigned int insect::numberOfLegs = 6;

insect::insect()
{
}


insect::~insect()
{
}

unsigned int insect::legs()
{
  return numberOfLegs;
}
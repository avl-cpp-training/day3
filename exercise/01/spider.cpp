#include "spider.h"

const unsigned int spider::numberOfLegs = 8;

spider::spider()
{
}


spider::~spider()
{
}

unsigned int spider::legs()
{
  return numberOfLegs;
}
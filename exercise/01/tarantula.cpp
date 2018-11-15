#include "tarantula.h"

const std::wstring tarantula::name = L"tarantula";

tarantula::tarantula()
{
}


tarantula::~tarantula()
{
}

std::wstring tarantula::species()
{
  return name;
}
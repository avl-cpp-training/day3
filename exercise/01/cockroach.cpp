#include "cockroach.h"

const std::wstring cockroach::name = L"cockroach";

cockroach::cockroach()
{
}


cockroach::~cockroach()
{
}

std::wstring cockroach::species()
{
  return name;
}

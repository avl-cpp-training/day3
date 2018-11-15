#pragma once
#include "insect.h"


class cockroach :
  public insect
{
public:
  cockroach();
  ~cockroach();
  std::wstring species();

private:
  static const std::wstring name;
};


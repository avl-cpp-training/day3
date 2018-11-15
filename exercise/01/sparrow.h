#pragma once
#include "bird.h"

class sparrow :
  public bird
{
private:
  static const std::wstring name;
public:
  sparrow();
  ~sparrow();
  std::wstring species();
};


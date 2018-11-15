#pragma once
#include "spider.h"

class tarantula :
  public spider
{
private:
  static const std::wstring name;
public:
  tarantula();
  ~tarantula();
  std::wstring species();
};


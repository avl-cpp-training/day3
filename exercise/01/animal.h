#pragma once

#include <string>

class animal
{
public:
  virtual ~animal() = default;

  virtual std::wstring species() = 0;
  virtual unsigned int legs() = 0;
};


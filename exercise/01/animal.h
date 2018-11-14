#pragma once
#include <string>

class animal
{
public:
  animal(unsigned int legs, const wchar_t species[]);
  virtual ~animal() = default;

  std::wstring species() const;
  unsigned int legs() const;

private:
  unsigned int legs_;
  const wchar_t * const species_;
};

class spider : public animal
{
public:
  spider(const wchar_t species[]);
};

class insect : public animal
{
public:
  insect(const wchar_t species[]);
};

class bird : public animal
{
public:
  bird(const wchar_t species[]);
};

class tarantula : public spider
{
public:
  tarantula();
};

class cockroach : public insect
{
public:
  cockroach();
};

class sparrow : public bird
{
public:
  sparrow();
};

animal* animal_factory(int id);
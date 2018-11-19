#pragma once
#include <string>
#include <vector>

class animal
{
public:
  animal();
  virtual ~animal() = 0;
  virtual std::wstring species() = 0;
  virtual unsigned int legs() = 0;
};

class bird : public animal
{
public:
  unsigned int legs() override;
};

class sparrow : public bird
{
public:
  std::wstring species() override;
};

class insect : public animal
{
public:
  unsigned int legs() override;
};

class cockroach : public insect
{
public:
  std::wstring species() override;
};

class spider : public animal
{
public:
  unsigned int legs() override;
};

class tarantula : public spider
{
public:
  std::wstring species() override;
};

class leg_counter
{
private:
  std::vector<std::unique_ptr<animal>> animals;
public:
  std::wstring add_animal(std::unique_ptr<animal> &a);
  unsigned int legs() const;
};

std::unique_ptr<animal> animal_factory(int animal_type);
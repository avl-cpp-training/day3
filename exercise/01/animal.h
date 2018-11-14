#pragma once
#include <string>

class animal
{
public:
  virtual ~animal() = default;
  virtual std::wstring species() const = 0;
  virtual unsigned int legs() const = 0;
};

class insect : public animal
{
public:
  unsigned int legs() const override;
};

class cockroach : public insect
{
public:
  std::wstring species() const override;
};

class bird : public animal
{
public:
  unsigned int legs() const override;
};

class sparrow : public bird
{
public:
  std::wstring species() const override;
};

class spider : public animal
{
public:
  unsigned int legs() const override;
};

class tarantula : public spider
{
public:
  std::wstring species() const override;
};

class leg_counter
{
public:
  leg_counter();
  std::wstring add_animal(std::unique_ptr<animal>);
  unsigned int legs() const;

private:
  unsigned int legCount;
};

std::unique_ptr<animal> animal_factory(int id);

enum AnimalIds
{
  cockroachId = 1,
  sparrowId = 2,
  tarantulaId = 3
};

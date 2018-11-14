#pragma once
#include <string>
#include <vector>

class animal
{
public:
  virtual std::wstring species() const noexcept = 0;
  virtual unsigned int legs() const noexcept = 0;
  virtual ~animal() = 0;
};

class insect : public animal
{
  unsigned legs() const noexcept override;
};

class bird : public animal
{
  unsigned legs() const noexcept override;
};

class spider : public animal
{
  unsigned legs() const noexcept override;
};

class cockroach : public insect
{
  std::wstring species() const noexcept override;
};


class sparrow : public bird
{
  std::wstring species() const noexcept override;
};


class tarantula : public spider
{
  std::wstring species() const noexcept override;
};


class leg_counter
{
private:
  std::vector<std::unique_ptr<animal>> animals_;
public:
  std::wstring add_animal(std::unique_ptr<animal> animal);
  unsigned legs() const;
};

std::unique_ptr<animal> animal_factory(int animal);

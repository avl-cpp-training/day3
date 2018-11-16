#pragma once
#include <string>
#include <memory>

enum anuanimal_enum
{
  cockroach_id = 1,
  sparrow_id = 2,
  tarantula_id = 3
};

class animal
{
public:
  virtual std::wstring species() const = 0;
  virtual unsigned int legs() const = 0;
  virtual ~animal() = default;
};

std::unique_ptr<animal> animal_factory(anuanimal_enum id);

class animal_base : public animal
{
public:
  animal_base(unsigned int legs, const std::wstring& species);

  std::wstring species() const override;
  unsigned int legs() const override;

private:
  unsigned int legs_;
  std::wstring species_;
};

class spider : public animal_base
{
public:
  spider(const std::wstring& species);
};

class insect : public animal_base
{
public:
  insect(const std::wstring& species);
};

class bird : public animal_base
{
public:
  bird(const std::wstring& species);
};

class tarantula : public spider
{
public:
  static const anuanimal_enum id = tarantula_id;
  tarantula();
};

class cockroach : public insect
{
public:
  static const anuanimal_enum id = cockroach_id;
  cockroach();
};

class sparrow : public bird
{
public:
  static const int anuanimal_enum = sparrow_id;
  sparrow();
};
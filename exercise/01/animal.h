#pragma once
#include <string>
#include <vector>

class animal {
public:
  virtual std::wstring species() const = 0;
  virtual unsigned int legs() const = 0;
  virtual ~animal() = default;
};

//---------------- Insects

class insect : public animal {
  unsigned legs() const override;
};

class cockroach : public insect {
public:
  std::wstring species() const override;
};

//---------------- Birds

class bird : public animal {
public:
  unsigned legs() const override;
};

class sparrow : public bird {
public:
  std::wstring species() const override;
};

//---------------- Spiders

class spider : public animal {
public:
  unsigned legs() const override;
};

class tarantula : public spider {
public:
  std::wstring species() const override;
};

//---------------- leg_counter

class leg_counter {
  unsigned int legs_ = 0;
public:
  unsigned int legs() const;
  std::wstring add_animal(const std::unique_ptr<animal>& concrete_animal);
};

//---------------- animal_factory
std::unique_ptr<animal> animal_factory(int of_type);
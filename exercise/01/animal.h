#pragma once

#include <string>


class animal
{
public:
  virtual ~animal() = default;

  virtual unsigned int legs() const = 0;
  virtual std::wstring species() const = 0;
};

///////////////////////////////////////////////////
class insect : public animal
{
public:

  unsigned int legs() const override;
};


//////////////////////////////////////////////////
class cockroach : public insect
{
public:

  std::wstring species() const override;
};


//////////////////////////////////////////////////
class bird : public animal
{
public:

  unsigned int legs() const override;
};


//////////////////////////////////////////////////
class sparrow : public bird
{
public:

  std::wstring species() const override;
};



//////////////////////////////////////////////////
class spider : public animal
{
public:

  unsigned int legs() const override;
};


///////////////////////////////////////////////////
class tarantula : public spider
{
public:

  std::wstring species() const override;
};



//////////////////////////////////////////////////
enum animalID
{
  eCockroach = 1,
  eSparrow,
  eTarantula
};


namespace  
{
  using namespace std;

  unique_ptr<animal> animal_factory(int id)
  {
    switch (id)
    {
      case eCockroach:
      {
        return make_unique<cockroach>();
      }

      case eSparrow:
      {
        return make_unique<sparrow>();
      }

      case eTarantula:
      {
        return make_unique<tarantula>();
      }

      default:
      {
        return nullptr;
      }
    }
  }
}


//////////////////////////////////////////////////
class leg_counter
{
public:
  leg_counter() : m_lLegCount(0) {};
  ~leg_counter() = default;

  std::wstring add_animal(const std::unique_ptr<animal> NewAnimal);
  const unsigned int legs();

private:
  unsigned int m_lLegCount;
};



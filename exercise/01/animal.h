#pragma once
#include <string>

class animal
{
public:
	virtual std::wstring species() const = 0;
	virtual unsigned int legs() const= 0;
	virtual ~animal() {};
};

class insect : public animal {};

class cockroach : public insect
{
	std::wstring species() const override;
	unsigned int legs() const override;
public:
	~cockroach();
};

class bird : public animal { };

class sparrow : public bird
{
	std::wstring species() const override;
	unsigned int legs() const override;
public:
	~sparrow();
};

class spider : public animal {};

class tarantula : public spider
{
	std::wstring species() const override;
	unsigned int legs() const override;
public:
	~tarantula();
};

class animal_factory
{
public:
	animal_factory(int id);
	animal* create_animal() const;
private:
	int id;
};

class leg_counter 
{
	unsigned int counter = 0;
public:
	std::wstring add_animal(animal_factory&);
	unsigned int legs() const;
};

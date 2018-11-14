#pragma once
#include <string>

class animal
{
public:
	virtual std::wstring species() = 0;
	virtual unsigned int legs() = 0;
	virtual ~animal() {};
};

class insect : public animal {};

class cockroach : public insect
{
	std::wstring species() override;
	unsigned int legs() override;
public:
	~cockroach();
};

class bird : public animal { };

class sparrow : public bird
{
	std::wstring species() override;
	unsigned int legs() override;
public:
	~sparrow();
};

class spider : public animal {};

class tarantula : public spider
{
	std::wstring species() override;
	unsigned int legs() override;
public:
	~tarantula();
};

class animal_factory
{
public:
	animal_factory(int id);
	animal* create_animal();
private:
	int id;
};

class leg_counter 
{
	unsigned int counter = 0;
public:
	std::wstring add_animal(animal_factory&);
	unsigned int legs();
};

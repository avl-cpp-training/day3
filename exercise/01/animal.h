#pragma once
#include <string>

class animal
{
public:
	std::wstring species() const;
	unsigned int legs() const;
};

class insect : public animal
{

};

class bird : public animal
{

};

class spider : public  animal
{

};

class cockroach : public insect
{

};

class sparrow : public bird
{

};

class tarantula : public spider
{

};

class leg_counter
{
public:
	std::wstring add_animal(const animal& animal);
	unsigned int legs() const;
};

animal animal_factory(int index);
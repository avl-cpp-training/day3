#pragma once
#include <string>
#include <list>

class animal
{
public:
	virtual std::wstring species() = 0;
	virtual unsigned int legs() = 0;

};

class insect : public animal
{
	unsigned int legs() override;
};

class cockroach : public insect
{
	std::wstring species() override;
};

class bird : public animal
{
	unsigned int legs() override;
};

class sparrow : public  bird
{
	std::wstring species() override;
};

class spider : public animal
{
	unsigned int legs() override;
};

class  tarantula :public spider
{
	std::wstring species() override;
};

class leg_counter
{
	std::list<animal*> animals_;
public:
	std::wstring add_animal(animal * animal);
	unsigned int legs();
};

namespace animal_type
{
	enum {
		cockroach = 1,
		sparrow,
		tarantula
	};
}

animal* animal_factory(int animal);


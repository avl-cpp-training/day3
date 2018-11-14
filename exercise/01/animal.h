#pragma once
class animal 
{
public:
	virtual animal& species() = 0;
	virtual const wchar_t* c_str() = 0;
	virtual const unsigned int legs() = 0;
};

class insect : public animal
{
public:
	//virtual const wchar_t *c_str() override { return L"insect"; }
	animal& species() override { return *this; }
};

class bird : public animal
{
public:
	//virtual const wchar_t* c_str() override { return L"bird";}
	animal& species() override { return *this; }
};

class spider : public animal 
{
public:
	//virtual const wchar_t* c_str() override { return L"spider"; }
	animal& species() override { return *this; }
};

class cockroach : public insect 
{
public:
	const wchar_t* c_str() override { return L"cockroach"; }
	const unsigned int legs() override { return 6u; }
};

class sparrow : public bird 
{
public:
	const wchar_t* c_str() override { return L"sparrow"; }
	const unsigned int legs() override { return 2u; }
};

class tarantula : public spider 
{
public:
	const wchar_t* c_str() override { return L"tarantula"; }
	const unsigned int legs() override { return 8u; }
};

class leg_counter 
{
private:
	unsigned int number_of_legs;
public:
	leg_counter();
	~leg_counter();
	animal& add_animal(animal& a);
	unsigned int legs();
};

animal& animal_factory(int id);
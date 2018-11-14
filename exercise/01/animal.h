#pragma once
#include <string>

class animal
{
public:
	virtual std::wstring species() const = 0;
	virtual unsigned int legs() const = 0;
	virtual ~animal() = 0;
};

class insect : public animal
{
public:
	~insect() {};
	unsigned int legs() const override;
private:
	static const unsigned int number_of_legs = 6;
};

class bird : public animal
{
public:
	~bird() {};
	unsigned int legs() const override;
private:
	static const unsigned int number_of_legs = 2;
};

class spider : public  animal
{
public:
	~spider() {};
	unsigned int legs() const override;
private:
	static const unsigned int number_of_legs = 8;
};

class cockroach : public insect
{
public:
	~cockroach() {};
	std::wstring species() const override;
private:
	static const std::wstring type;
};

class sparrow : public bird
{
public:
	~sparrow() {};
	std::wstring species() const override;
private:
	static const std::wstring type;
};

class tarantula : public spider
{
public:
	~tarantula() {};
	std::wstring species() const override;
private:
	static const std::wstring type;
};

class animal_factory
{
public:
	animal_factory(unsigned int animal_num) : animal_num(animal_num) {};
	std::unique_ptr<animal> create_animal() const;

private:
	unsigned int animal_num;
};

class leg_counter
{
public:
	std::wstring add_animal(const animal_factory& factory);
	unsigned int legs() const;

private:
	unsigned int number_of_legs = 0;
};

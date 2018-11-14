#pragma once
#include <string>
#include <vector>

class animal
{
public:
	virtual ~animal() = default;
	virtual std::wstring species() const = 0;
	virtual unsigned legs() const = 0;
};

class insect : public animal
{
public:
	unsigned legs() const override;
protected:
	static const unsigned legCount = 6;
};

class cockroach : public insect
{
public:
	std::wstring species() const override;
protected:
	const std::wstring speciesName = L"cockroach";
};

class bird : public animal
{
public:
	unsigned legs() const override;
protected:
	static const unsigned legCount = 2;
};

class sparrow : public bird
{
public:
	std::wstring species() const override;
protected:
	const std::wstring speciesName = L"sparrow";
};

class spider : public animal
{
public:
	unsigned legs() const override;
protected:
	static const unsigned legCount = 8;
};

class tarantula : public spider
{
public:
	std::wstring species() const override;
protected:
	const std::wstring speciesName = L"tarantula";
};

class leg_counter
{
public:
	std::wstring add_animal(animal*) const;
private:
	std::vector<animal> animals;
};

enum Animals { Cockroach = 1, Sparrow = 2, Tarantula = 3 };

inline animal* animal_factory(int num)
{
	if (num == Animals::Cockroach)
	{
		return new cockroach;
	}
	if (num == Animals::Sparrow)
	{
		return new sparrow;
	}
	if (num == Animals::Tarantula)
	{
		return new tarantula;
	}

	return nullptr;
}
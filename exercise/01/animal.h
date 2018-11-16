#pragma once
#include <string>

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
	std::wstring add_animal(std::unique_ptr<animal>);
	unsigned legs() const;
private:
	unsigned animalCount = 0;
};

std::unique_ptr<animal> animal_factory(int num);
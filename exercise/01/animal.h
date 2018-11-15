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
	unsigned int legs() const override;
};

class bird : public animal
{
public:
	unsigned int legs() const override;
};

class spider : public animal
{
public:
	unsigned int legs() const override;
};

class cockroach : public insect
{
public:
	std::wstring species() const override;
};

class sparrow : public bird
{
public:
	std::wstring species() const override;
};

class tarantula : public spider
{
public:
	std::wstring species() const override;
};

std::unique_ptr<animal> animal_factory(unsigned int id);

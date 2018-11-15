#include "animal.h"

animal::~animal()
{
}

unsigned int insect::legs() const
{
	return 6u;
}

unsigned int bird::legs() const
{
	return 2u;
}

unsigned int spider::legs() const
{
	return 8u;
}

std::wstring cockroach::species() const
{
	return std::wstring(L"cockroach");
}

std::wstring sparrow::species() const
{
	return std::wstring(L"sparrow");
}

std::wstring tarantula::species() const
{
	return std::wstring(L"tarantula");
}

std::unique_ptr<animal> animal_factory(unsigned int id)
{
	switch (id)
	{
	case 1: return std::make_unique<cockroach>();
	case 2: return std::make_unique<sparrow>();
	case 3: return std::make_unique<tarantula>();
	default: return nullptr;
	}
}

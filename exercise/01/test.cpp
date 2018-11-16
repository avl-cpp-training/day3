#include "CppUnitTest.h"
#include "leg_counter.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "animal.h"

TEST_CLASS(test_animal_hierarchy)
{
public:
	TEST_METHOD(concrete_insect)
	{
		cockroach c;
		insect& i = c;
		animal& a = c;
		Assert::AreEqual(L"cockroach", a.species().c_str());
		Assert::AreEqual(6u, a.legs());
	}
	TEST_METHOD(concrete_bird)
	{
		sparrow s;
		bird& b = s;
		animal& a = s;
		Assert::AreEqual(L"sparrow", a.species().c_str());
		Assert::AreEqual(2u, a.legs());
	}

	TEST_METHOD(concrete_spider)
	{
		tarantula t;
		spider& s = t;
		animal& a = t;
		Assert::AreEqual(L"tarantula", a.species().c_str());
		Assert::AreEqual(8u, a.legs());
	}

	TEST_METHOD(legg_counter_different_animals)
	{
		leg_counter lc;
		Assert::AreEqual(L"cockroach", lc.add_animal(animal_factory(cockroach_id)).c_str());
		Assert::AreEqual(L"sparrow",   lc.add_animal(animal_factory(sparrow_id)).c_str());
		Assert::AreEqual(L"tarantula", lc.add_animal(animal_factory(tarantula_id)).c_str());
		Assert::AreEqual(16u, lc.legs());
	}

	TEST_METHOD(legg_counter_same_animal)
	{
		leg_counter lc;
		lc.add_animal(animal_factory(sparrow_id));
		lc.add_animal(animal_factory(sparrow_id));
		Assert::AreEqual(4u, lc.legs());
	}
};

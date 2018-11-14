#include "animal.h"

leg_counter::leg_counter() : number_of_legs (0)
{
}

leg_counter::~leg_counter() 
{
}

animal& leg_counter::add_animal (animal& a) 
{
	number_of_legs += a.legs();
	return a;
}

unsigned int leg_counter::legs() 
{
	return number_of_legs;
}

animal& animal_factory(int id) 
{
	animal* a = nullptr;

	/*----------------------------------memory leak ???????------------------------------
	*/
	switch (id) 
	{
	case 1:
		a = new cockroach;
		break;
	case 2:
		a = new sparrow;
		break;
	case 3:
		a = new tarantula;
		break;
	}

	return *a;

}
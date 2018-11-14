#include <string>

class animal
{
public:
	virtual std::wstring species() const = 0;
	virtual unsigned int legs() const = 0;
	virtual ~animal() {};
};

class animal_factory
{
	animal* a;
public:
	animal_factory(unsigned int id);
	~animal_factory();
	animal* get_animal() const;
};


class insect : public animal
{
public:
	unsigned int legs() const override;
	~insect() {};
};

class cockroach : public insect
{
public:
	std::wstring species() const override;
	~cockroach() {}
};

class bird : public animal
{
public:
	unsigned int legs() const override;
	~bird() {};
};

class sparrow : public bird
{
public:
	std::wstring species() const override;
	~sparrow() {};
};

class spider : public animal
{
public:
	unsigned int legs() const override;
	~spider() {};
};

class tarantula : public spider
{
public:
	std::wstring species() const override;
	~tarantula() {};
};

class leg_counter
{
	unsigned int nlegs;
public:
	leg_counter() : nlegs(0) {};
	std::wstring add_animal(const animal_factory& animal_fac);
	unsigned int legs() const;
};

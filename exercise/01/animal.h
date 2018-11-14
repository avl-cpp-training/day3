#pragma once

#include <string>
#include <memory>

class animal
{
public:
    constexpr std::wstring const& species() const noexcept { return species_; }
    constexpr unsigned legs() const noexcept { return legs_; };
    virtual ~animal() = 0;
protected:
    animal(std::wstring const& species, std::uint8_t legs);
private:
    std::wstring species_;
    unsigned legs_;
};

class insect : public animal
{
protected:
    using animal::animal;
};

class spider : public animal
{
protected:
    using animal::animal;
};

class bird : public animal
{
protected:
    using animal::animal;
};

class cockroach : public insect
{
    constexpr static auto species_name = L"cockroach";
    constexpr static auto legs = 6u;
public:
    constexpr static auto animal_id = 1;
    cockroach();
};

class tarantula : public spider
{
    constexpr static auto species_name = L"tarantula";
    constexpr static auto legs = 8u;
public:
    constexpr static auto animal_id = 3;
    tarantula();
};

class sparrow : public bird
{
    constexpr static auto species_name = L"sparrow";
    constexpr static auto legs = 2u;
public:
    constexpr static auto animal_id = 2;
    sparrow();
};

std::unique_ptr<animal> animal_factory(int animal_id);

class leg_counter
{
public:
    std::wstring const& add_animal(std::unique_ptr<animal> const& ptr) noexcept;
    constexpr unsigned legs() const noexcept { return legs_; }
private:
    unsigned legs_{ 0 };
 };




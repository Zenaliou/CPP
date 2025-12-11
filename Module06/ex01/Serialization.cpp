#include "Serialization.hpp"

Serialization::Serialization()
{
	std::cout << "Serialization Constructor called" << std::endl;
}

Serialization::Serialization(const Serialization& other)
{
	std::cout << "Serialization copy Constructor called" << std::endl;
	*this = other;
}

Serialization &Serialization::operator=(const Serialization& other)
{
	(void)other;
	std::cout << "Serialization assignement operator called" << std::endl;
	return *this;
}

Serialization::~Serialization()
{
	std::cout << "Serialization Destructor called" << std::endl;
}

uintptr_t Serialization::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serialization::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}
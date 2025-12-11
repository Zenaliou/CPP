#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <iostream>
#include <string>
#include <stdint.h>

struct Data
{
	std::string string;
	int i;
	double d;
	float f;
};

class Serialization
{
	private:

	public:
		Serialization();
		Serialization(const Serialization& other);
		Serialization& operator=(const Serialization& other);
		~Serialization();

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};


#endif
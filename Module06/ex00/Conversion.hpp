#ifndef CONVERSION_HPP
#define CONVERSION_HPP

#include <string>
#include <iostream>
#include <climits>
#include <cstdlib>

class Conversion
{
	private:

	public:
		Conversion();
		Conversion(const Conversion& other);
		Conversion& operator=(const Conversion& other);
		~Conversion();

		static void Convert(std::string& input);

};


#endif
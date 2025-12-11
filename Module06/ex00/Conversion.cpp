#include "Conversion.hpp"

Conversion::Conversion()
{
	std::cout << "Conversion Constructor called" << std::endl;
}

Conversion::Conversion(const Conversion& other)
{
	std::cout << "Conversion copy Contructor called" << std::endl;
	*this = other;
}

Conversion &Conversion::operator=(const Conversion& other)
{
	(void) other;
	std::cout << "Conversion assignement operator called" << std::endl;
	return (*this);
}

Conversion::~Conversion()
{
	std::cout << "Conversion Destructor called" << std::endl;
}

static int detectType(const std::string& input)
{
	// Pseudo-literals
	if (input == "nan" || input == "nanf" || input == "+inf" || input == "-inf" 
		|| input == "+inff" || input == "-inff" || input == "inff")
		return 4; // special

	// Char: a single non-numeric character
	if (input.length() == 1 && !std::isdigit(input[0]))
		return 0; // char

	// Check if it's a valid number
	bool hasPoint = false;
	bool hasF = false;
	size_t start = 0;
	
	if (input[0] == '+' || input[0] == '-')
		start = 1;
	
	if (start >= input.length())
		return -1; // invalid
	
	for (size_t i = start; i < input.length(); i++)
	{
		if (input[i] == '.')
		{
			if (hasPoint)
				return -1; // two dots
			hasPoint = true;
		}
		else if (input[i] == 'f' && i == input.length() - 1)
		{
			hasF = true;
		}
		else if (!std::isdigit(input[i]))
		{
			return -1; // invalid
		}
	}
	
	if (hasF && hasPoint)
		return 2; // float
	if (hasPoint)
		return 3; // double
	return 1; // int
}

static void convertToChar(const std::string& input, int type)
{
	std::cout << "char: ";
	
	if (type == 4) // pseudo-literals
	{
		std::cout << "impossible" << std::endl;
		return;
	}
	
	if (type == 0) // already a char
	{
		std::cout << "'" << input[0] << "'" << std::endl;
		return;
	}
	
	// Convert to double to check the range
	char *end;
	double value = std::strtod(input.c_str(), &end);
	
	if (value < 0 || value > 127)
	{
		std::cout << "impossible" << std::endl;
		return;
	}
	
	char c = static_cast<char>(value);
	if (!std::isprint(c))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << c << "'" << std::endl;
}

static void convertToInt(const std::string& input, int type)
{
	std::cout << "int: ";
	
	if (type == 4) // pseudo-literals
	{
		std::cout << "impossible" << std::endl;
		return;
	}
	
	if (type == 0) // char
	{
		std::cout << static_cast<int>(input[0]) << std::endl;
		return;
	}
	
	char *end;
	double value = std::strtod(input.c_str(), &end);
	
	if (value < INT_MIN || value > INT_MAX)
	{
		std::cout << "impossible" << std::endl;
		return;
	}
	
	std::cout << static_cast<int>(value) << std::endl;
}

static void convertToFloat(const std::string& input, int type)
{
	std::cout << "float: ";
	
	if (type == 0) // char
	{
		std::cout << static_cast<float>(input[0]) << ".0f" << std::endl;
		return;
	}
	
	char *end;
	double value = std::strtod(input.c_str(), &end);
	
	// Handle pseudo-literals
	if (input == "nan" || input == "nanf")
	{
		std::cout << "nan" << std::endl;
		return;
	}
	if (input == "+inf" || input == "+inff")
	{
		std::cout << "+inff" << std::endl;
		return;
	}
	if (input == "-inf" || input == "-inff" || input == "inff")
	{
		std::cout << "-inff" << std::endl;
		return;
	}
	
	float f = static_cast<float>(value);
	std::cout << f;
	if (f == static_cast<int>(f))
		std::cout << ".0";
	std::cout << "f" << std::endl;
}

static void convertToDouble(const std::string& input, int type)
{
	std::cout << "double: ";
	
	if (type == 0) // char
	{
		std::cout << static_cast<double>(input[0]) << ".0" << std::endl;
		return;
	}
	
	char *end;
	double value = std::strtod(input.c_str(), &end);
	
	// Handle pseudo-literals
	if (input == "nan" || input == "nanf")
	{
		std::cout << "nan" << std::endl;
		return;
	}
	if (input == "+inf" || input == "+inff")
	{
		std::cout << "+inf" << std::endl;
		return;
	}
	if (input == "-inf" || input == "-inff" || input == "inff")
	{
		std::cout << "-inf" << std::endl;
		return;
	}
	
	std::cout << value;
	if (value == static_cast<int>(value))
		std::cout << ".0";
	std::cout << std::endl;
}

void Conversion::Convert(std::string& input)
{
	int type = detectType(input);
	
	if (type == -1)
	{
		std::cout << "Error: Invalid input" << std::endl;
		return;
	}
	
	convertToChar(input, type);
	convertToInt(input, type);
	convertToFloat(input, type);
	convertToDouble(input, type);
}

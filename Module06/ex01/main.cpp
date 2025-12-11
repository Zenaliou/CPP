#include "Serialization.hpp"

void	print_data(Data *data) {
	std::cout << "data double " << data->d << std::endl;
	std::cout << "data int " << data->i << std::endl;
	std::cout << "data string " << data->string << std::endl;
	std::cout << "data float " << data->f << std::endl;
}

int main(void)
{
	std::cout << "=========== Data ===========" << std::endl;
	Data data;
	data.d = 42.0;
	data.i = 42;
	data.string = "a";
	data.f = 42.0f;

	print_data(&data);

	std::cout << "=========== Serialization ===========" << std::endl;
	uintptr_t raw = Serialization::serialize(&data);

	Data *test = Serialization::deserialize(raw);
	print_data(test);
}
#include "Fixed.hpp"

int main(void)
{
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    
    std::cout << b << std::endl;
    
    std::cout << Fixed::max(a, b) << std::endl;
    
    return 0;
}


// int main() {
//     Fixed a(5.05f);
//     Fixed b(2);
//     Fixed c = a + b;

//     std::cout << a << " + " << b << " = " << c << std::endl;

//     c = a - b;
//     std::cout << a << " - " << b << " = " << c << std::endl;

//     c = a * b;
//     std::cout << a << " * " << b << " = " << c << std::endl;

//     c = a / b;
//     std::cout << a << " / " << b << " = " << c << std::endl;

//     return 0;
// }

// int main()
// {
//     Fixed a(10);
//     Fixed b(4.2f);

//     std::cout << "a = " << a << ", b = " << b << std::endl;
//     std::cout << "a > b ? " << (a > b) << std::endl;
//     std::cout << "a < b ? " << (a < b) << std::endl;
//     std::cout << "a == b ? " << (a == b) << std::endl;
//     std::cout << "a != b ? " << (a != b) << std::endl;
//     std::cout << "a >= b ? " << (a >= b) << std::endl;
//     std::cout << "a <= b ? " << (a <= b) << std::endl;

//     return 0;
// }

// int main()
// {
//     Fixed a;

//     std::cout << "a = " << a << std::endl;

//     std::cout << "++a = " << ++a << std::endl;
//     std::cout << "a = " << a << std::endl;

//     std::cout << "a++ = " << a++ << std::endl;
//     std::cout << "a = " << a << std::endl;

//     std::cout << "--a = " << --a << std::endl;
//     std::cout << "a-- = " << a-- << std::endl;
//     std::cout << "a = " << a << std::endl;

//     return 0;
// }


// int main()
// {
//     Fixed a(1.1f);
//     Fixed b(3.3f);

//     std::cout << "a = " << a << ", b = " << b << std::endl;

//     std::cout << "min(a,b) = " << Fixed::min(a,b) << std::endl;
//     std::cout << "max(a,b) = " << Fixed::max(a,b) << std::endl;

//     const Fixed c(10.5f);
//     const Fixed d(42.42f);

//     std::cout << "min(c,d) = " << Fixed::min(c,d) << std::endl;
//     std::cout << "max(c,d) = " << Fixed::max(c,d) << std::endl;

//     return 0;
// }

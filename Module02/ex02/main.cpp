#include "Fixed.hpp"
#include <iostream>

int main(void)
{
    std::cout << "=== Constructor Tests ===" << std::endl;
    Fixed a;                    // Default constructor
    Fixed b(42);               // Int constructor
    Fixed c(42.42f);           // Float constructor
    Fixed d(b);                // Copy constructor
    
    std::cout << "a (default): " << a << std::endl;
    std::cout << "b (42): " << b << std::endl;
    std::cout << "c (42.42f): " << c << std::endl;
    std::cout << "d (copy of b): " << d << std::endl;
    
    std::cout << "\n=== Arithmetic Operators Tests ===" << std::endl;
    Fixed x(5.05f);
    Fixed y(2);
    
    std::cout << "x = " << x << ", y = " << y << std::endl;
    std::cout << "x + y = " << (x + y) << std::endl;
    std::cout << "x - y = " << (x - y) << std::endl;
    std::cout << "x * y = " << (x * y) << std::endl;
    std::cout << "x / y = " << (x / y) << std::endl;
    
    std::cout << "\n=== Comparison Operators Tests ===" << std::endl;
    Fixed p(10);
    Fixed q(4.2f);
    
    std::cout << "p = " << p << ", q = " << q << std::endl;
    std::cout << "p > q ? " << (p > q ? "true" : "false") << std::endl;
    std::cout << "p < q ? " << (p < q ? "true" : "false") << std::endl;
    std::cout << "p == q ? " << (p == q ? "true" : "false") << std::endl;
    std::cout << "p != q ? " << (p != q ? "true" : "false") << std::endl;
    std::cout << "p >= q ? " << (p >= q ? "true" : "false") << std::endl;
    std::cout << "p <= q ? " << (p <= q ? "true" : "false") << std::endl;
    
    std::cout << "\n=== Increment/Decrement Operators Tests ===" << std::endl;
    Fixed m;
    
    std::cout << "m initial = " << m << std::endl;
    std::cout << "++m = " << ++m << std::endl;
    std::cout << "m after ++m = " << m << std::endl;
    std::cout << "m++ = " << m++ << std::endl;
    std::cout << "m after m++ = " << m << std::endl;
    std::cout << "--m = " << --m << std::endl;
    std::cout << "m after --m = " << m << std::endl;
    std::cout << "m-- = " << m-- << std::endl;
    std::cout << "m after m-- = " << m << std::endl;
    
    std::cout << "\n=== Min/Max Functions Tests ===" << std::endl;
    Fixed r(1.1f);
    Fixed s(3.3f);
    
    std::cout << "r = " << r << ", s = " << s << std::endl;
    std::cout << "min(r, s) = " << Fixed::min(r, s) << std::endl;
    std::cout << "max(r, s) = " << Fixed::max(r, s) << std::endl;
    
    // Test with constants
    const Fixed const_r(10.5f);
    const Fixed const_s(42.42f);
    
    std::cout << "\nConstant objects test:" << std::endl;
    std::cout << "const_r = " << const_r << ", const_s = " << const_s << std::endl;
    std::cout << "min(const_r, const_s) = " << Fixed::min(const_r, const_s) << std::endl;
    std::cout << "max(const_r, const_s) = " << Fixed::max(const_r, const_s) << std::endl;
    
    std::cout << "\n=== Original Subject Test ===" << std::endl;
    Fixed original_a;
    Fixed const original_b(Fixed(5.05f) * Fixed(2));
    
    std::cout << original_a << std::endl;
    std::cout << ++original_a << std::endl;
    std::cout << original_a << std::endl;
    std::cout << original_a++ << std::endl;
    std::cout << original_a << std::endl;
    std::cout << original_b << std::endl;
    std::cout << Fixed::max(original_a, original_b) << std::endl;
    
    return 0;
}

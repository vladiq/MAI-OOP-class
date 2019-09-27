#include <iostream>

#include "angle.hpp"

int main(void)
{
	Angle a;
	a.Read(std::cin);

	std::cout << a.To_decimal() << std::endl;
	std::cout << a.To_radian() << std::endl;
	std::cout << std::endl;

	Angle b;
	b.Read(std::cin);

	a.Plus(b).Write(std::cout);
	a.Minus(b).Write(std::cout);
	std::cout << std::endl;

	int divisor;
	std::cin >> divisor;
	a.Division(divisor).Write(std::cout);
	std::cout << std::endl;

	std::cout << a.Sin() << std::endl;
	std::cout << a.Cos() << std::endl;
	std::cout << std::endl;

	if (a.Comparison(b) == 0) {
		std::cout << "a == b" << std::endl;
	} else if (a.Comparison(b) == -1) {
		std::cout << "a > b" << std::endl;
	} else {
		std::cout << "a < b" << std::endl;
	}

	return 0;
}

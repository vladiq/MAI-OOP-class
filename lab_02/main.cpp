#include <iostream>

#include "angle.hpp"

int main(void)
{
	Angle a;
	std::cin >> a;

	std::cout << std::endl;

	std::cout << a.To_decimal() << std::endl;
	std::cout << a.To_radian() << std::endl;
	std::cout << std::endl;

	Angle b;
	std::cin >> b;
	std::cout << std::endl;

	Angle result;

	result = a + b;
	std::cout << result;

	result = a - b;
	std::cout << result;

	std::cout << std::endl;

	int divisor;
	std::cin >> divisor;
	result = a / divisor;
	std::cout << result;
	std::cout << std::endl;

	std::cout << a.Sin() << std::endl;
	std::cout << a.Cos() << std::endl;
	std::cout << std::endl;

	if (a == b) {
		std::cout << "a == b" << std::endl;
	} else if (a > b) {
		std::cout << "a > b" << std::endl;
	} else {
		std::cout << "a < b" << std::endl;
	}
	std::cout << std::endl;

	result = 2_piece;
	std::cout << result;

	result = 6_piece;
	std::cout << result;
	std::cout << std::endl;

	return 0;
}

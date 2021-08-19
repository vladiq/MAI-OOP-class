#include "angle.hpp"

Angle::Angle()
{
	deg = 0;
	min = 0;
}

void Angle::To_normal()
{
	if (min < 0) {
		while (min < 0) {
			deg -= 1;
			min += 60;
		}
	} else if (min >= 60) {
		while (min >= 60) {
			deg += 1;
			min -= 60;
		}
	}

	if (deg < 0) {
		deg = 360 - (-deg % 360);
	} else {
		deg %= 360;
	}
}

void Angle::Read(std::istream &is)
{
	is >> deg >> min;
	To_normal();
}

void Angle::Write(std::ostream &os) const
{
	os << deg << ' ' << min << std::endl;
}

double Angle::To_decimal() const
{
	return deg + (double)min / 60.0;
}

double Angle::To_radian() const
{
	return 3.14159265 * (deg + (double)min / 60.0) / 180.0;
}

Angle Angle::Plus(Angle &b) const
{
	Angle result;
	result.deg = deg + b.deg;
	result.min = min + b.min;

	result.To_normal();

	return result;
}

Angle Angle::Minus(Angle &b) const
{
	Angle result;

	result.deg = deg - b.deg;
	result.min = min - b.min;

	result.To_normal();

	return result;
}

Angle Angle::Division(int number) const
{
	Angle result;

	result.deg = deg / number;
	result.min = min / number;

	return result;
}

double Angle::Sin() const
{
	double x = To_radian();
	return sin(x);
}

double Angle::Cos() const
{
	double x = To_radian();
	return cos(x);
}

short Angle::Comparison(Angle &b) const
{
	double a_dec = To_decimal();
	double b_dec = b.To_decimal();

	if (a_dec == b_dec) {
		return 0;
	} else if (a_dec > b_dec) {
		return -1;
	} else {
		return 1;
	}
}

#include "angle.h"

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
	if ((deg == 0 || deg == 180) && min == 0) {
		return 0;
	}
	double t = To_radian();
	double sinx = t;

	for (int i = 1; i < 10; ++i)
	{
		double mult = - To_radian() * To_radian() / ((2 * i + 1) * (2 * i));
		t *= mult;
		sinx += t;
	}
	return sinx;
}

double Angle::Cos() const
{
	if ((deg == 90 || deg == 270) && min == 0) {
		return 0;
	}
	double mul = 1, div = 1,res = 0, x = To_radian();
	for (int i = 1; i < 20; i += 2)
	{
		res += mul / div;
		mul *= -x * x;
		div *= i * (i + 1);
	}
	return res;
}

short Angle::Comparison(Angle &b) const
{
	double a_dec = To_decimal();
	double b_dec = b.To_decimal();

	if (a_dec == b_dec) {
		return 0;
	} else if (a_dec > b_dec) {
		return 1;
	} else {
		return 2;
	}
}

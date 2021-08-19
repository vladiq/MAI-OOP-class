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
	return M_PI * (deg + (double)min / 60.0) / 180.0;
}

Angle operator+ (const Angle& lhs, const Angle& rhs)
{
	Angle res(lhs.deg + rhs.deg, lhs.min + rhs.min);
	res.To_normal();
	return res;
}

Angle operator- (const Angle& lhs, const Angle& rhs)
{
	Angle res(lhs.deg - rhs.deg, lhs.min - rhs.min);
	res.To_normal();
	return res;
}

Angle operator/ (const Angle& lhs, const int divisor)
{
	return Angle(lhs.deg / divisor, lhs.min / divisor);
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

bool operator> (const Angle& lhs, const Angle& rhs)
{
	return (lhs.To_decimal() > rhs.To_decimal());
}

bool operator< (const Angle& lhs, const Angle& rhs)
{
	return (lhs.To_decimal() < rhs.To_decimal());
}

bool operator== (const Angle& lhs, const Angle& rhs)
{
	return (lhs.To_decimal() == rhs.To_decimal());
}

std::istream& operator>> (std::istream& is, Angle &a)
{
	is >> a.deg >> a.min;
	return is;
}

std::ostream& operator<< (std::ostream& os, Angle &a)
{
	os << a.deg << ' ' << a.min << std::endl;
	return os;
}

Angle operator"" _piece(unsigned long long divisor)
{
	Angle res(360, 0);
	res = res / divisor;
	return res;
}

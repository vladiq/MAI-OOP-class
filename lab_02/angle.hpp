#ifndef ANGLE_H
#define ANGLE_H

#include <iostream>
#include <cmath>

class Angle 
{
private:
	int deg;
	int min;

public:
	Angle();
	Angle(int d, int m): deg(d), min(m)
	{}

	void To_normal(); //приведение отрицательных углов и минут к диапазону [0..360]deg [0..59]min

	void Read(std::istream &is); //считывание угла
	void Write(std::ostream &os) const; //вывод угла

	double To_decimal() const; //перевод в десятичное представление
	double To_radian() const; //перевод в радианы

	friend Angle operator+ (const Angle& lhs, const Angle& rhs);
	friend Angle operator- (const Angle& lhs, const Angle& rhs);
	friend Angle operator/ (const Angle& lhs, const int divisor);

	double Sin() const;
	double Cos() const;

	friend bool operator> (const Angle& lhs, const Angle& rhs);
	friend bool operator< (const Angle& lhs, const Angle& rhs);
	friend bool operator== (const Angle& lhs, const Angle& rhs);

	friend std::istream& operator>> (std::istream& is, Angle& a);
	friend std::ostream& operator<< (std::ostream& os, Angle& a);
};

Angle operator"" _piece(unsigned long long divisor); // возвращает угол 360 градусов, делённый на divisor

#endif // ANGLE_H

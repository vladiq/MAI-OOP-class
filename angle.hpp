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

	void To_normal(); //приведение отрицательных углов и минут к диапазону [0..360]deg [0..59]min

	void Read(std::istream &is); //считывание угла
	void Write(std::ostream &os) const; //вывод угла

	double To_decimal() const; //перевод в десятичное представление
	double To_radian() const; //перевод в радианы

	Angle Plus(Angle &b) const; //сложение углов
	Angle Minus(Angle &b) const; //вычитание углов
	Angle Division(int number) const; //деление угла на целое число

	double Sin() const; 
	double Cos() const;

	short Comparison(Angle &b) const; //сравнение углов
};

#endif // ANGLE_H

#include <iostream>
#include "Rational.h"
#include "math.h"
using namespace std;

//Конструкторы
Rational::Rational()
{
	numer = 0;
	denom = 1;
}

Rational::Rational(int number)
{
	numer = number;
	denom = 1;
}

Rational::Rational(double number) {
	number = int(number * 10 + 0.5) / double(10);//сократили
	int count = 1;
	while (number - (int)number != 0) {
		number *= 10;
		count *= 10;
	}
	numer = number;
	denom = count;
	simplify();
}
Rational::Rational(int n, int d)
{
	numer = n;
	denom = d;
}


//Операторы присваивания
Rational& Rational::operator =(const Rational& r) {
	numer = r.numer;
	denom = r.denom;

	return *this;
}

Rational& Rational::operator +=(const Rational& r)
{
	numer = (numer * r.denom + denom * r.numer);
	denom *= r.denom;
	// this - указатель на себя
	// *this - ссылка на себя
	simplify(); // упрощение
	return *this;
}

Rational& Rational::operator -=(const Rational& r)
{
	return (*this += (-r));
}

Rational& Rational:: operator *=(const Rational& r)
{
	numer *= r.numer;
	denom *= r.denom;
	simplify();
	return *this;
}
Rational& Rational:: operator /=(const Rational& r)
{
	Rational temp = r;
	temp.numer = r.denom;
	temp.denom = r.numer;
	return *this *= temp;

}



//Операторы сложения, вычитания, умножения, деления;
Rational Rational::operator -() const
{
	Rational r(-numer, denom);
	return r;
}

Rational Rational:: operator -(const Rational& r) const
{
	Rational temp = *this;
	return temp -= r;
}

Rational Rational:: operator *(const Rational& r) const
{
	Rational temp = *this;
	return temp *= r;
}

Rational Rational:: operator /(const Rational& r) const
{
	Rational temp = *this;
	return temp /= r;
}

Rational Rational::operator +(const Rational& r) const
{
	// this - указатель на себя
	// *this - ссылка на себя
	Rational res(*this);
	// Используем готовую операцию добавления
	return res += r;
}

Rational& Rational::operator ++()
{
	numer += denom;
	return *this;
}

Rational Rational::operator ++(int)
{
	Rational r(*this);
	numer += denom;
	return r;
}

Rational& Rational::operator --()
{
	numer -= denom;
	return *this;
}
Rational Rational::operator --(int)
{
	Rational r(*this);
	numer -= denom;
	return r;
}
//Операторы сравнения
Rational Rational:: the_common_denominator(const Rational& r)
{
	Rational temp = *this;
	temp.numer *= r.denom;
	temp.denom *= r.denom;
	return temp;
	
}

bool Rational::operator ==(const Rational& r) const
{
	return (numer == r.numer) && (denom == r.denom);
}

bool Rational::operator !=(const Rational& r) const
{
	return !(*this == r);
}
bool Rational:: operator <=(const Rational& r) const
{
	Rational temp1= *this;
	Rational temp2 = r;
	temp1.the_common_denominator(r);
	temp2.the_common_denominator(*this);
	return temp1.numer <= temp2.numer;
}
bool Rational:: operator >=(const Rational& r) const
{
	return (r <= *this);
}
bool  Rational::operator <(const Rational& r) const
{
	return !(*this >= r);
}
bool Rational:: operator >(const Rational& r) const
{
	return !(*this <= r);
}


Rational::operator int() const
{
	return numer / denom;
}
Rational::operator double() const
{
	return ((double)numer) / denom;
}

istream& operator >>(istream& in, Rational& r)
{
	in >> r.numer >> r.denom;
	return in;
}
ostream& operator <<(ostream& out, const Rational& r)
{
	out << r.numer << "/" << r.denom;
	return out;
}


//Функции степени и нахождения корня, квадратное уравнние, simplify;
Rational Rational::finding_the_root() {
	double numer1 = sqrt (numer);
	double denom1 = sqrt (denom);
	Rational numer_rational(numer1);
	Rational denom_rational(denom1);

	return (numer_rational/denom_rational);
}
Rational Rational::finding_the_pow( int x)
{
	Rational temp = *this;
	for (int i = 0; i < x-1; i++) {
		temp *= *this;
	}
	return temp;
}

void Rational::simplify()
{
	int temp_n = abs(numer);
	int temp_d = denom;
	while (temp_n != 0 && temp_d != 0) {
		if (temp_n > temp_d) { temp_n%=temp_d; }
		else { temp_d %= temp_n; }
	}

	int NOD = (temp_d == 0) ? temp_n : temp_d; // проверка на 0;
	numer /= abs(NOD);
	denom /= abs(NOD);
}

void equation(Rational a, Rational b, Rational c){
	Rational D = b.finding_the_pow(2) - Rational(4) * a * c;
	if (D < Rational (0)){
		throw("Действительных корней нет");
	}
	if (a == Rational(0)) {
		cout << "Вычисляем корни" << endl;
		Rational x = -c / b;
		cout << x << endl;
		return;
	}

	if (D == Rational(0)) {
		cout << "Вычисляем корни" << endl;
		Rational x = (-b + D.finding_the_root()) / ( Rational(2) * a);
		cout << x << endl;
		return;
	}
	cout << "Вычисляем корни" << endl;
	Rational x1 = (-b + D.finding_the_root()) / (Rational(2) * a);
	Rational x2 = (-b - D.finding_the_root()) / (Rational(2) * a);
	cout << x1 <<" "<< x2 << endl;
}
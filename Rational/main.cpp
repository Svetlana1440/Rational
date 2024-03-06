#include <iostream>
#include "Rational.h"
#include "equation.h"

using namespace std;
int main() {
	setlocale(LC_ALL, "ru-RU");
	Rational a, b(40, 7), c(6, 17);
	// ������������
	cout << a << " �������� �� ������ ����������� " << endl;
	cout << endl;
	//
	cout << b << " �������� �� ����������� � ����� ����� ������ " << endl;
	cout << endl;
	//
	cout << c << " �������� �� ����������� � ����� ������ ������� " << endl;
	cout << endl;
	//
	a = b;
	cout << "a =  b =" << b << endl;
	cout << endl;
	//
	a += b;
	cout << "a += b =" << a << endl;
	cout << endl;
	//
	cout << "a+b =" << a + b << endl;
	cout << endl;
	//
	cout << "a-b =" << a - b << endl;
	cout << endl;
	//
	a -= b;
	cout << "a -= b =" << a << endl;
	cout << endl;
	//
	cout << "-a =" << -a << endl;
	cout << endl;
	//
	a *= b;
	cout << "a *= b =" << a << endl;
	cout << endl;
	//
	cout << "a * b =" << a * b<< endl;
	cout << endl;
	//
	cout << "a / b =" << a / b << endl;
	cout << endl;
	//
	a /=b;
	cout << "a /= b =" << a << endl;
	cout << endl;
	//
	cout << "a++" << a++ << endl;
	cout << endl;
	//
	cout << "++a" << ++a << endl;
	cout << endl;
	//
	cout << "a--" << a-- << endl;
	cout << endl;
	//
	cout << "--a" << --a << endl;
	cout << endl;

	//��������� ���������
	bool first_oper = a < b;
	cout << "a<b: " << first_oper << endl;
	cout << endl;
	//
	bool second_oper = a > b;
	cout << "a>b: " << second_oper << endl;
	cout << endl;
	//
	bool third_oper = a <= b;
	cout << "a<=b: " << third_oper << endl;
	cout << endl;
	//
	bool fourth_oper = a >= b;
	cout << "a>=b: " << fourth_oper << endl;
	cout << endl;
	//
	bool fifth_oper = a != b;
	cout << "a!=b: " << fifth_oper << endl;
	cout << endl;
	//
	bool sixth_oper = a == b;
	cout << "a==b: " << sixth_oper << endl;
	//
	a.the_common_denominator(b);
	cout << " a � ����������� b " << b << endl;
	cout << endl;
	//
	int d = int(a);
	cout << "int �� a = " << d << endl;
	cout << endl;
	//
	Rational x1(4, 256);
	Rational y = finding_the_sqrt(x1);
	cout << "������� ���������� ������ �� a: " << y << endl;
	cout << endl;
	//
	Rational x2(-4, 256);
	cout << "x = " << x2 << endl;
	cout << "���������� �������� x =  " << abs(x2) << endl;
	cout << endl;
	//
	cout << "x = " << x2 << endl;
	cout << "����������� �������� x2 =  " << round(x2) << endl;
	cout << endl;


	Rational j(2, 3), l(2, 5), lk(2, 9);
	equation(j, l, lk);
	cout << j << l << lk;
	cout << endl;

}

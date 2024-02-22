#include <iostream>
#include "Rational/Rational.h"

using namespace std;
int main() {
	setlocale(LC_ALL, "ru-RU");
	Rational a(1,3), b(40,7), c(6,17);
	equation(a, b, c);
}
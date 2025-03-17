#include "Rational.h"
#include "Integer.h"

int main()
{
	Integer num1 = 5;
	Integer denum1 = 10;
	Integer num2 = -10;
	Integer denum2 = 15;
	Rational number1 { num1, denum1 };
	Rational number2 { num2, denum2 };
	std::cout <<-(number1 + number2);
}
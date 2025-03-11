#include "Rational.h"
#include "Integer.h"

int main()
{
	Integer num{ -1 };
	std::cout << num++;
	std::cout << num;
}
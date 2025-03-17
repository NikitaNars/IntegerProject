#pragma once
#include "Integer.h"
#include <string>

class Rational
{
public:
	Rational();
	Rational( Integer num, Integer deNum);
	Rational(Integer number);

	void SetSign(const bool sign);

	void SetNum(const Integer units);

	void SetDeNum(const Integer units);


	bool GetSign();

	Integer GetNum();

	Integer GetDeNum();


	bool isPlus() const;

	bool isMinus() const;

	bool isProper() const;

	bool isNotProper() const;

	bool isSame(const Rational& other) const;

	Rational recRational();
	Rational simplification();
	Integer CountUnits() const;


	friend Rational operator+(const Rational& a, const Rational& b);
	friend Rational operator-(const Rational& a, const Rational& b);
	friend Rational operator/(const Rational& a, const Rational& b);
	friend Rational operator*(const Rational& a, const Rational& b);


	bool operator==(const Rational& other) const;

	bool operator<=(const Rational& other) const;

	bool operator>=(const Rational& other) const;

	bool operator<(const Rational& other) const;

	bool operator>(const Rational& other) const;

	bool operator!=(const Rational& other) const;

	Rational operator+();
	Rational operator-();

	friend std::ostream& operator<<(std::ostream& out, const Rational& obj);;


private:
	bool sign_;
	Integer num_;
	Integer denum_;
};






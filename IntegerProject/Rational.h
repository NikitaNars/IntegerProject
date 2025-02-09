#pragma once
#include "Integer.h"
#include <string>

class Rational
{
public:
	Rational();
	Rational(bool sign, Integer num, Integer deNum);
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

	std::string recRational();

	Integer CountUnits() const;

	bool operator==(const Rational& other) const;

	bool operator<=(const Rational& other) const;

	bool operator>=(const Rational& other) const;

	bool operator<(const Rational& other) const;

	bool operator>(const Rational& other) const;

	bool operator!=(const Rational& other) const;


private:
	bool sign_;
	Integer num_;
	Integer denum_;
};






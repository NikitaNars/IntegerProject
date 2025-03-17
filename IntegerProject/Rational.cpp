#include "Rational.h"

Rational::Rational() :Rational(Integer(0), Integer(1)) {};
Rational::Rational( Integer num, Integer deNum) : num_(num), denum_(deNum)
{
	if (deNum < 1)
	{
		throw std::invalid_argument("Знаменатель не может быть меньше нуля");
	}
	

}


Rational::Rational(Integer number)
{
	if (number < 0)
	{
		sign_ = true;
		num_ = Integer(-static_cast<Integer>(number));
		denum_ = static_cast<Integer>(1);
	}
	else
	{
		sign_ = false;
		num_ = number;
		denum_ = static_cast<Integer>(1);
	}
}
void Rational::SetSign(const bool sign)
{
	sign_ = sign;
}
void Rational::SetNum(const Integer num)
{
	num_ = num;
}
void Rational::SetDeNum(const Integer denum)
{
	denum_ = denum;
}

bool Rational::GetSign()
{
	return sign_;
}

Integer Rational::GetNum()
{
	return num_;
}

Integer Rational::GetDeNum()
{
	return denum_;
}

bool Rational::isProper() const
{
	return num_ < denum_;
}

bool Rational::isNotProper() const
{
	return num_ > denum_;
}

bool Rational::isPlus() const
{
	return sign_ == false;
}

bool Rational::isMinus() const
{
	return sign_ == true;
}


bool Rational::isSame(const Rational& other) const
{
	return this == &other;
}

Rational Rational::recRational()
{
	Integer temp{ num_ };
	num_ = denum_;
	denum_ = temp;
	return *this;
}
Rational Rational::simplification()
{
	int NOD = num_.NOD(denum_);
	num_ = num_ / NOD;
	denum_ = denum_ / NOD;
	return *this;
}
Integer Rational::CountUnits() const
{
	Integer units = num_ / denum_;
	return units;
}

Rational operator+(const Rational& a, const Rational& b)
{
	Integer NOK = a.denum_.NOK(b.denum_);
	Integer multiA, multiB;
	multiA = NOK / a.denum_;
	multiB = NOK / b.denum_;
	Rational result{ a.num_ * multiA + b.num_ * multiB, NOK };
	return result;
}
Rational operator-(const Rational& a, const Rational& b)
{
	Integer NOK = a.denum_.NOK(b.denum_);
	Integer multiA, multiB;
	multiA = NOK / a.denum_;
	multiB = NOK / b.denum_;
	Rational result{ a.num_ * multiA - b.num_ * multiB, NOK };
	return result;
}
Rational operator*(const Rational& a, const Rational& b)
{
	Rational result{ a.num_ * b.num_, a.denum_ * b.denum_ };
	return result;
}
Rational operator/(const Rational& a, const Rational& b)
{
	Rational result{ a.num_ * b.denum_, a.denum_ * b.num_ };
	return result;
}
bool Rational::operator==(const Rational& other) const
{
	if (sign_ == other.sign_)
	{
		return num_ == other.num_ && denum_ == other.denum_;
	}
	return false;

}

bool Rational::operator!=(const Rational& other) const
{
	if (sign_ == other.sign_)
	{
		if (num_ != other.num_ && denum_ != other.denum_)
		{
			return true;
		}
		else if (num_ == other.num_ && denum_ != other.denum_)
		{
			return true;
		}
		else if (num_ != other.num_ && denum_ == other.denum_)
		{
			return true;
		}
	}
	return false;
}

bool Rational::operator<(const Rational& other) const
{
	Integer num1;
	Integer num2;
	if (sign_ == other.sign_)
	{
		num1 = num_ * other.denum_;
		num2 = denum_ * other.num_;
		return num1 < num2;
	}
	else if (sign_ < other.sign_)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Rational::operator>(const Rational& other) const
{
	Integer num1;
	Integer num2;
	if (sign_ == other.sign_)
	{
		num1 = num_ * other.denum_;
		num2 = denum_ * other.num_;
		return num1 > num2;
	}
	else if (sign_ > other.sign_)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Rational::operator<=(const Rational& other) const
{
	Integer num1;
	Integer num2;
	if (sign_ == other.sign_)
	{
		num1 = num_ * other.denum_;
		num2 = denum_ * other.num_;
		return num1 <= num2;
	}
	else if (sign_ < other.sign_)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Rational::operator>=(const Rational& other) const
{
	Integer num1;
	Integer num2;
	if (sign_ == other.sign_)
	{
		num1 = num_ * other.denum_;
		num2 = denum_ * other.num_;
		return num1 >= num2;
	}
	else if (sign_ > other.sign_)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Rational Rational::operator+()
{
	return *this;
}
Rational Rational::operator-()
{
	Rational result{ *this };
	result.sign_ = !result.sign_;
	return result;
}

std::ostream& operator<<(std::ostream& out, const Rational& obj)
{
	if (obj.sign_ == true)
	{
		return out << "-(" << obj.num_ << "/" << obj.denum_ << ")";
	}
	else
	{
		return out << obj.num_ << "/" << obj.denum_;
	}
}
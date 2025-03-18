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
		num_ = Integer(-static_cast<Integer>(number));
		denum_ = static_cast<Integer>(1);
	}
	else
	{

		num_ = number;
		denum_ = static_cast<Integer>(1);
	}
}
void Rational::SetSign(const bool sign)
{
	num_.SetSign(sign);
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
	return num_.GetSign();
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

bool Rational::isPlus() 
{
	return num_.GetSign() == false;
}

bool Rational::isMinus() 
{
	return num_.GetSign() == true;
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
bool Rational::operator==( Rational& other) const
{
	if (num_.GetSign() == other.num_.GetSign())
	{
		return num_ == other.num_ && denum_ == other.denum_;
	}
	return false;

}

bool Rational::operator!=( Rational& other) const
{
	if (num_.GetSign() == other.num_.GetSign())
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

bool Rational::operator<( Rational& other) const
{
	Integer num1;
	Integer num2;
	if (num_.GetSign() == other.num_.GetSign())
	{
		num1 = num_ * other.denum_;
		num2 = denum_ * other.num_;
		return num1 < num2;
	}
	else if (num_.GetSign() < other.num_.GetSign())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Rational::operator>( Rational& other) const
{
	Integer num1;
	Integer num2;
	if (num_.GetSign() == other.num_.GetSign())
	{
		num1 = num_ * other.denum_;
		num2 = denum_ * other.num_;
		return num1 > num2;
	}
	else if (num_.GetSign() > other.num_.GetSign())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Rational::operator<=( Rational& other) const
{
	Integer num1;
	Integer num2;
	if (num_.GetSign() == other.num_.GetSign())
	{
		num1 = num_ * other.denum_;
		num2 = denum_ * other.num_;
		return num1 <= num2;
	}
	else if (num_.GetSign() < other.num_.GetSign())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Rational::operator>=( Rational& other) const
{
	Integer num1;
	Integer num2;
	if (num_.GetSign() == other.num_.GetSign())
	{
		num1 = num_ * other.denum_;
		num2 = denum_ * other.num_;
		return num1 >= num2;
	}
	else if (num_.GetSign() > other.num_.GetSign())
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
	result.num_.SetSign(!result.num_.GetSign());

	return result;
}

std::ostream& operator<<(std::ostream& out, const Rational& obj)
{
	if (obj.num_.GetSign() == true)
	{
		return out << obj.num_ << "/" << obj.denum_ ;
	}
	else
	{
		return out << obj.num_ << "/" << obj.denum_;
	}
}
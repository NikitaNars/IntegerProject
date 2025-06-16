#include "Integer.hpp"


Integer::Integer() :Integer(false, 0u) {}
Integer::Integer(bool sign, unsigned units) :sign_(sign), units_(units) {}
Integer::Integer(int number)
{
	if (number < 0)
	{
		sign_ = true;
		units_ = ::abs(number);
	}
	else
	{
		sign_ = false;
		units_ = static_cast <unsigned> (number);
	}
}
//�����
void Integer::SetSign(const bool& sign) 
{
	this->sign_ = sign;
}

void Integer::SetUnits(const unsigned& units)
{
	this->units_ = units;
}

//�����
bool Integer::GetSign() const
{
	return sign_;
}

unsigned Integer::GetUnits() const
{
	return units_;
}
//��������
bool Integer::isOdd()const
{
	return bool(units_ % 2 == 0);
}
//����������
bool Integer::isNotOdd()const
{
	return bool(units_ % 2 != 0);
}
//���������������
bool Integer::isPlus()const
{
	return !sign_;
}
//���������������
bool Integer::isMinus()const
{
	return sign_;
}
//�������� �� ����� ������
bool Integer::isSimpleNum()const
{
	int count = 0;
	for (int i = 1; i <= units_; i++)
	{
		if (units_ % i)
		{
			count++;
		}
	}
	if (count == 2)
	{
		return true;
	}
	return false;
}



//���
int Integer::NOD(Integer other)const {

	int a = units_;
	while (other.units_ != 0) {
		int temp = other.units_;
		other.units_ = a % other.units_;
		a = temp;
	}
	return a;
}
//���
int Integer::NOK(const Integer other)const
{
	return (units_ * other.units_) / NOD(other.units_);
}
//�������� �� 2 ����� ����� � ��� �� �������� � ���������
bool Integer::tryNums(const Integer& other) const
{
	if (units_ == other.units_)
	{
		return true;
	}
	else if (&units_ == &other.units_)
	{
		return true;
	}
	return false;
}
//�������� +
Integer operator+(const Integer& a, const Integer& b)
{
	Integer result;
	if (a.sign_ == b.sign_)
	{
		result.sign_ = a.sign_;
		result.units_ = a.units_ + b.units_;
	}
	else
	{
		if (a.units_ > b.units_)
		{
			result.sign_ = a.sign_;
			result.units_ = a.units_ - b.units_;
		}
		else if (a.units_ < b.units_)
		{
			result.sign_ = b.sign_;
			result.units_ = b.units_ - a.units_;
		}
		else
		{
			result.sign_ = false;
			result.units_ = 0;
		}
	}
	return result;
}
//�������� -
Integer operator-(const Integer& a, const Integer& b)
{
	Integer result;
	if (a.sign_ == b.sign_)
	{
		result.sign_ = a.sign_;
		result.units_ = a.sign_ - b.sign_;
	}
	else
	{
		if (a.sign_ > b.sign_)
		{
			result.sign_ = a.sign_;
			result.units_ = a.units_ + b.units_;
		}
		else if (a.sign_ < b.sign_)
		{
			result.sign_ = b.sign_;
			result.units_ = b.units_ + a.units_;
		}
		else
		{
			result.sign_ = false;
			result.units_ = 0;
		}
	}
	return result;
}
//�������� *
Integer operator*(const Integer& a, const Integer& b)
{
	Integer result;
	if (a.sign_ == b.sign_)
	{
		result.sign_ = a.sign_;
	}
	else
	{
		if (a.sign_ > b.sign_)
		{
			result.sign_ = a.sign_;
		}
		else if (a.sign_ < b.sign_)
		{
			result.sign_ = b.sign_;
		}
		else
		{
			result.sign_ = false;
			result.units_ = 0;
		}
	}
	result.units_ = a.units_ * b.units_;
	return result;
}
//�������� /

Integer operator/(const Integer& a, const Integer& b)
{
	Integer result;
	if (a.sign_ != b.sign_)
	{

		result.units_ = a.units_ / b.units_;

		result.units_ = a.units_ / b.units_;

		result.sign_ = true;
	}
	else
	{
		result.units_ = a.units_ / b.units_;
		result.sign_ = false;
	}
	return result;


}
//�������� %




Integer operator%(const Integer& a, const Integer& b)
{
	Integer result;
	if (a.sign_ == b.sign_)
	{
		result.sign_ = a.sign_;
		result.units_ = a.units_ % b.units_;
	}
	else
	{
		if (a.sign_ > b.sign_)
		{
			result.sign_ = a.sign_;
			result.units_ = a.sign_ % b.sign_;
		}
		else if (a.sign_ < b.sign_)
		{
			result.sign_ = b.sign_;
			result.units_ = b.sign_ % a.sign_;
		}
		else
		{
			result.sign_ = false;
			result.units_ = 0;
		}
	}
	return result;
}
//�������� +=
Integer& Integer::operator+=(const Integer& other)
{

	*this = *this + other;
	return *this;
}
//�������� -=
Integer& Integer::operator-=(const Integer& other)
{
	*this = *this - other;
	return *this;

}
//�������� *=
Integer& Integer::operator*=(const Integer& other)
{
	*this = *this - other;
	return *this;
}
//�������� /=
Integer& Integer::operator/=(const Integer& other)
{
	*this = *this / other;
	return *this;
}
//�������� ++
Integer Integer::operator++(int)
{
	if (sign_ == true)
	{
		Integer temp = units_;
		units_--;
		return temp;
	}
	else
	{
		Integer temp = units_;
		units_++;
		return temp;
	}
	return units_;
}
//�������� --
Integer Integer::operator--(int)
{
	if (sign_ == true)
	{
		Integer temp = units_;
		units_++;
		return temp;
	}
	else
	{
		Integer temp = units_;
		units_--;
		return temp;
	}
	
}



//�������� ++
Integer Integer::operator++()
{
	if (sign_ == true)
	{
		--(units_);
	}
	else
	{
		++(units_);
	}
	return units_;
}

//�������� ++
Integer Integer::operator--()
{
	if (sign_ == true)
	{
		++(units_);
	}
	else
	{
		--(units_);
	}
	return units_;
}



//�������� ==
bool Integer::operator==(const Integer& other) const
{
	if (sign_ == other.sign_)
	{
		return units_ == other.units_;
	}
	return false;
}
//�������� !=
bool Integer::operator!=(const Integer& other) const
{
	if (sign_ == other.sign_)
	{
		return units_ != other.units_;
	}
	return true;
}
//�������� <
bool Integer::operator<(const Integer& other) const {
	if (sign_ == other.sign_) {
		return units_ < other.units_;
	}
	else if (sign_ == true && other.sign_ == false) {
		return false;
	}
	return true;
}
//�������� >
bool Integer::operator>(const Integer& other) const
{
	if (sign_ == other.sign_)
	{
		return units_ > other.units_;
	}
	else if (sign_ == true && other.sign_ == false)
	{
		return true;
	}
	return false;
}
//�������� <=
bool Integer::operator<=(const Integer& other) const
{
	if (sign_ == other.sign_)
	{
		return units_ <= other.units_;
	}
	else if (sign_ == true && other.sign_ == false)
	{
		return false;
	}
	return true;
}
//�������� >=
bool Integer::operator>= (const Integer& other) const
{
	if (sign_ == other.sign_)
	{
		return units_ >= other.units_;
	}
	else if (sign_ == true && other.sign_ == false)
	{
		return true;
	}
	return false;
}
//�������� +
Integer Integer::operator+()
{
	return units_;
}



//�������� -
Integer Integer::operator-()
{
	Integer res = { *this };
	if (sign_ == true)
	{
		res.sign_ = false;
	}
	else
	{
		res.sign_ = true;
	}
	return res;
}
// �����
std::ostream& operator<<(std::ostream& out, const Integer& other)
{
	if (other.sign_ == true && other.units_ != 0)
	{
		out << '-' << other.units_;
	}
	else
	{
		out << other.units_;
	}
	return out;
}

#pragma once


#include <iostream>
#include <numeric>
class Integer
{
public:


	Integer();
	Integer(bool sign, unsigned units);
	Integer(int number);


	void SetSign(const bool& sign);
	void SetUnits(const unsigned& units);



	bool GetSign();
	unsigned GetUnits();


	bool isOdd()const;

	bool isNotOdd()const;

	bool isPlus()const;

	bool isMinus()const;
	bool isSimpleNum()const;

	int NOD(Integer other)const;

	int NOK(const Integer other)const;

	bool tryNums(const Integer& other)const;



	friend Integer operator+(const Integer& a, const Integer& b);

	friend Integer operator-(const Integer& a, const Integer& b);

	friend Integer operator*(const Integer& a, const Integer& b);

	friend Integer operator/(const Integer& a, const Integer& b);

	friend Integer operator%(const Integer& a, const Integer& b);

	Integer& operator+=(const Integer& other);

	Integer& operator-=(const Integer& other);

	Integer& operator*=(const Integer& other);

	Integer& operator/=(const Integer& other);




	Integer operator++(int);


	Integer operator--(int);



	Integer operator++();


	Integer operator--();




	bool operator==(const Integer& other) const;
	bool operator!=(const Integer& other) const;
	bool operator<(const Integer& other) const;
	bool operator>(const Integer& other) const;
	bool operator<=(const Integer& other) const;
	bool operator>=(const Integer& other) const;
	friend std::ostream& operator<<(std::ostream& out, const Integer& other);




	Integer operator+();





	Integer operator-();








private:
	bool sign_;
	unsigned units_;

};
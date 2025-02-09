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

	void SetSign(const bool &sign);
	void SetUnits(const unsigned &units);


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




	// проверка на четность
	bool isOdd()const;
	// проверка на положительность
	bool isPlus()const;
	// проверка является ли число простым
	bool isSimpleNum()const;
	// нахождение наибольшего общего делителя
	int NOD(Integer other)const;
	// нахождение наибольшего общего кратного
	int NOK(Integer other)const;
	// проверка являются ли числа взаимнопростыми
	bool tryNums(const Integer &other)const;

	// --------------------------------------------------
	// Сумма
	friend Integer operator+(const Integer& a, const Integer& b);
	// Разность
	friend Integer operator-(const Integer& a, const Integer& b);
	// Умножение
	friend Integer operator*(const Integer& a, const Integer& b);
	// Частное
	friend Integer operator/(const Integer& a, const Integer& b);
	// Деление с остатком
	friend Integer operator%(const Integer& a, const Integer& b);
	// Операторы присваивания
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



	Integer operator+();


	Integer operator-();








private:
	bool sign_;
	unsigned units_;

};
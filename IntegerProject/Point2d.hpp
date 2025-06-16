#pragma once
#ifndef POINT2D_HPP
#define POINT2D_HPP
#include "Integer.hpp"

#endif // !POINT2D_HPP

class Point2d
{
public:
	//������������
	Point2d();
	Point2d(int x, int y);

	//��� ���
	double GetX();
	double GetY();
	void SetX(double x);
	void SetY(double y);

	//==
	bool operator==( Point2d other);

	//������
	bool isEquls( Point2d other);
	double Distance( Point2d other);


private:
	double x_, y_
};


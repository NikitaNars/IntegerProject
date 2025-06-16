#include "Point2d.hpp"
Point2d::Point2d() : Point2d(0, 0) {};
Point2d::Point2d(int x, int y)
{
	x_ = x;
	y_ = y;
	
}
double Point2d::GetX()
{
	return x_;
}
double Point2d::GetY()
{
	return y_;
}
void Point2d::SetX(double x)
{
	x_ = x;
}
void Point2d::SetY(double y)
{
	y_ = y;
}
bool Point2d::operator==( Point2d other)
{
	if (this->GetX() == other.GetX() && this->GetY() == other.GetY())
	{
		return true;
	}
	return false;
}
bool Point2d::isEquls( Point2d other)
{
	if (this->GetX() == other.GetX() && this->GetY() == other.GetY())
	{
		return true;
	}
	return false;
}
double Point2d::Distance( Point2d other)
{
	return sqrt(pow((other.GetX() - this->GetX()), 2) + pow((other.GetY() - this->GetY()), 2));
}
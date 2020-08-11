#include "Vector2D.h"

Vector2D::Vector2D()
{
}

Vector2D::Vector2D(const double& x, const double& y)
{
	this->x = x;
	this->y = y;
}

Vector2D::~Vector2D()
{}

double& Vector2D::X() {return x;}
double& Vector2D::Y() {return y;}
void Vector2D::zeroize() 
{
	this->x = 0;
	this->y = 0;
}

Vector2D operator + (Vector2D& first, Vector2D& second)
{
	return Vector2D(first.x + second.x, first.y + second.y); 
}

Vector2D operator - (Vector2D& first, Vector2D& second)
{
	return Vector2D(first.x - second.x, first.y - second.y);	
}

Vector2D operator * (Vector2D& vector, const double& num)
{
	return Vector2D (vector.x * num, vector.y * num);
}

Vector2D operator / (Vector2D& vector, const double& num)
{
	return Vector2D (vector.x / num, vector.y / num);
}

Vector2D& Vector2D::operator += (Vector2D& right) 
{
	x += right.x;
	y += right.y;
	return *this;
}

Vector2D& Vector2D::operator -= (Vector2D& right)
{
	x -= right.x;
	y -= right.y;
	return *this;
}

Vector2D& Vector2D::operator *= (const double& num)
{
	x *= num;
	y *= num;
	return *this;
}

Vector2D& Vector2D::operator /= (const double& num)
{
	x /= num;
	y /= num;
	return *this;
}

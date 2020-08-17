#include "Vector2D.h"

Vector2D::Vector2D()
{
}

Vector2D::Vector2D(const double& x, const double& y)
{
	xpos = x;
	ypos = y;
}

Vector2D::~Vector2D()
{}

double& Vector2D::x() {return xpos;}
double& Vector2D::y() {return ypos;}

void Vector2D::zeroize() 
{
	xpos = 0;
	ypos = 0;
}

Vector2D operator + (const Vector2D& first, const Vector2D& second)
{
	return Vector2D(first.xpos + second.xpos, first.ypos + second.ypos); 
}

Vector2D operator - (const Vector2D& first, const Vector2D& second)
{
	return Vector2D(first.xpos - second.xpos, first.ypos - second.ypos);	
}

Vector2D operator * (const Vector2D& first, const Vector2D& second)
{
	return Vector2D (first.xpos * second.xpos, first.ypos * second.ypos);
}

Vector2D operator * (const Vector2D& vector, const double& num)
{
	return Vector2D (vector.xpos * num, vector.ypos * num);
}

Vector2D operator / (const Vector2D& vector, const double& num)
{
	return Vector2D (vector.xpos / num, vector.ypos / num);
}

Vector2D& Vector2D::operator += (const Vector2D& right) 
{
	xpos += right.xpos;
	ypos += right.ypos;
	return *this;
}

Vector2D& Vector2D::operator -= (const Vector2D& right)
{
	xpos -= right.xpos;
	ypos -= right.ypos;
	return *this;
}

Vector2D& Vector2D::operator *= (const double& num)
{
	xpos *= num;
	ypos *= num;
	return *this;
}

Vector2D& Vector2D::operator /= (const double& num)
{
	xpos /= num;
	ypos /= num;
	return *this;
}

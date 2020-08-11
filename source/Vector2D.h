#ifndef VECTOR2D_H
#define VECTOR2D_H

class Vector2D
{
public:
	Vector2D ();
	Vector2D (const double& x, const double& y);
	~Vector2D ();
	void zeroize ();
	double& x();
	double& y();

	friend Vector2D operator + (Vector2D& first, Vector2D& second);
	friend Vector2D operator - (Vector2D& first, Vector2D& second);
	friend Vector2D operator * (Vector2D& vector, const double& num);
	friend Vector2D operator / (Vector2D& vector, const double& num);

	Vector2D& operator += (Vector2D& right);
	Vector2D& operator -= (Vector2D& right);
	Vector2D& operator *= (const double& num);
	Vector2D& operator /= (const double& num);
private:
	double xpos = 0;
	double ypos = 0;
};

#endif

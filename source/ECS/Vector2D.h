#ifndef VECTOR2D_H
#define VECTOR2D_H

class Vector2D
{
public:
	Vector2D ();
	Vector2D (double x, double y);
	~Vector2D ();
	void zeroize ();
	double& X();
	double& Y();

	friend Vector2D operator + (Vector2D& first, Vector2D& second);
	friend Vector2D operator - (Vector2D& first, Vector2D& second);
	friend Vector2D operator * (Vector2D& vector, double num);
	friend Vector2D operator / (Vector2D& vector, double num);

	Vector2D& operator += (Vector2D& right);
	Vector2D& operator -= (Vector2D& right);
	Vector2D& operator *= (double num);
	Vector2D& operator /= (double num);
private:
	double x = 0;
	double y = 0;
};





#endif


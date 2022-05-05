#include "Vect2D.h"
void Vect2D::SetXY(float _x, float _y)
{
	x = _x;
	y = _y;
	calcPolar();
}

void Vect2D::SetTR(float Rad, float _r)
{
	theta_.SetRad(Rad);
	r = _r;
	calcCart();
}

void Vect2D::SetTR(int Degrees, float _r)
{
	theta_.SetDeg(Degrees);
	r = _r;
	calcCart();
}
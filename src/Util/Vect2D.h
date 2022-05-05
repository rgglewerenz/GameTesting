#pragma once
#include "Platform/Platform.hpp"
using namespace sf;
namespace LIB
{
struct Theta
{
public:
	float Rad()
	{
		return _rads;
	}
	float Deg()
	{
		return _deg;
	}
	void SetDeg(float deg)
	{
		_deg = deg;
		calcRad();
	}
	void SetRad(float rad)
	{
		_rads = rad;
		calcDeg();
	}

private:
	float _rads, _deg;
	void calcDeg()
	{
		//TODO
	}
	void calcRad()
	{
		//TODO
	}
};
}
class Vect2D : Vector2f
{
public:
	Vect2D(float _x, float _y)
	{
		x = _x;
		y = _y;
		calcPolar();
	}

	void SetXY(float _x, float _y);
	void SetTR(float Rad, float _r);
	void SetTR(int Degrees, float _r);

	void calcCart();
	void calcPolar();

	LIB::Theta theta_;
	float r;
};
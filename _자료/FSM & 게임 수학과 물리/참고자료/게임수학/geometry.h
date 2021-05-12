#pragma once
#include "point.h"
#include <cmath>

#define PI		3.14159265f
#define Rad2Deg	57.29577951f
#define Deg2Rad	0.017453293f

// ���� �Լ��� ������� ���� ȣ���Ͽ� �� ������ ����� �����ϴ�.
#pragma intrinsic (sqrt, pow, atan, sin, cos)

class Circle
{
public:
	Point center;
	float radius;
};

// �� �� ������ �Ÿ�.
float Distance2D(const Point& p1, const Point& p2)
{
	return ((float)sqrt(pow(p2.GetX() - p1.GetX(), 2) + pow(p2.GetY() - p1.GetY(), 2)));
}

// �� �� ������ ����.
Point MidPoint2D(const Point& p1, const Point& p2)
{
	auto x = (p1.GetX() + p2.GetX()) * 0.5f;
	auto y = (p1.GetY() + p2.GetY()) * 0.5f;

	return Point(x, y);
}

bool CircleCollision(const Circle& c1, const Circle& c2)
{
	return (Distance2D(c1.center, c2.center) <= (c1.radius + c2.radius));
}

// �� �� ������ ����(Degree)
float CalculatorAngle2D(const Point& p1, const Point& p2)
{
	//���� ���.
	float angle = (float)atan((p2.GetY() - p1.GetY()) / (p2.GetX() - p1.GetX())) * Rad2Deg;
	// ��ī��Ʈ��ǥ�� ����, ��1��и�(x,y�� ���)�� �ִ� ���� ��.
	if (p2.GetY() < p1.GetY() && p2.GetX() > p1.GetX()) return angle;
	// ��2(x ����, y ���), 3(x, y ����)��и鿡 �ִ� ���� ��.
	else if ((p2.GetY() < p1.GetY() && p2.GetX() < p1.GetX()) ||
		(p2.GetY() > p1.GetY() && p2.GetX() < p1.GetX())) return angle + 180;
	// ��4��и�(x ���, y ����)
	else return angle + 360;
}

Point Direction2DWithRad(const float& radian)
{
	auto x = cos(radian);
	auto y = -sin(radian);

	return Point(x, y);
}
Point Direction2DWithDeg(const float& degree)
{
	return Direction2DWithRad(degree * Deg2Rad);
}
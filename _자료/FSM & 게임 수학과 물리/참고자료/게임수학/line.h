#pragma once
#include "point.h"

//�� ���� �մ� ������ ����.
float GetSlope(const Point& p1, const Point& p2)
{
	return (p2.GetY() - p1.GetY()) / (p2.GetX() - p1.GetX());
}

// �� ����� �����ϴ� ������ ����.
float PerpSlope(float slope)
{
	return -1 / slope;
}
// �� ������ �����ΰ�?
bool IsPerp(float slope1, float slope2)
{
	return (-1 == slope1 * slope2);
}
// �� ������ ������.
Point lineIntersect(const Point& p1, const float& slope1, const Point& p2, const float& slope2)
{
	auto x = (slope1 * p1.GetX() - slope2 * p2.GetX() + p2.GetY() - p1.GetY()) / (slope1 - slope2);
	auto y = slope1 * (x - p1.GetX()) + p1.GetY();
	// or y = slope2 * (x - p2.GetX()) + p2.GetY();

	return Point(x, y);
}
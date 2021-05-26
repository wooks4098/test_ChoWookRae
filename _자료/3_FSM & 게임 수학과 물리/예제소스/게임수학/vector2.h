#pragma once
#include<cmath>

#pragma intrinsic (sin, cos, sqrtf, asin, cosf, sinf)

#define PI		3.14159265f
#define Rad2Deg	57.29577951f
#define Deg2Rad	0.017453293f
#define GRAVITY 9.81f

// ��ī��Ʈ ��ǥ.
class Vector2
{
public:
	float x, y;

	Vector2() : x(0), y(0) {}
	Vector2(float x, float y) : x(x), y(y) {}

	Vector2 operator+(const Vector2& v)
	{
		Vector2 temp;
		temp.x = this->x + v.x;
		temp.y = this->y + v.y;

		return temp;
	}
	Vector2 operator-(const Vector2& v)
	{
		Vector2 temp;
		temp.x = this->x - v.x;
		temp.y = this->y - v.y;

		return temp;
	}
	Vector2 operator*(const float& value)
	{
		Vector2 temp;
		temp.x = this->x * value;
		temp.y = this->y * value;

		return temp;
	}
	void operator+=(const Vector2& v)
	{
		this->x = this->x + v.x;
		this->y = this->y + v.y;
	}
	Vector2 normalize()
	{
		float magnitude = sqrtf(pow(x, 2) + pow(y, 2));
		return Vector2(x / magnitude, y / magnitude);
	}
};
// �� ��ǥ.
class Polar
{
public:
	float magnitude, angle;

	Polar() : magnitude(0), angle(0) {}
};

Vector2 Normalize(const Vector2& v)
{
	float magnitude = sqrtf(pow(v.x, 2) + pow(v.y, 2));
	return Vector2(v.x / magnitude, v.y / magnitude);
}

Vector2 ScalarMultiply(const Vector2& v, const float& value)
{
	Vector2 temp;
	temp.x = v.x * value;
	temp.y = v.y * value;

	return temp;
}

Vector2 SumVector(const Vector2& v1, const Vector2& v2)
{
	Vector2 temp;
	temp.x = v1.x + v2.x;
	temp.y = v1.y + v2.y;

	return temp;
}

// ������ ����.
float DotProduct(const Vector2& v1, const Vector2& v2)
{
	return v1.x * v2.x + v1.y * v2.y;
}

Vector2 Polar2Comp(const Polar& p)
{
	Vector2 temp;
	temp.x = p.magnitude * cos(p.angle * Deg2Rad);
	temp.y = p.magnitude * -sin(p.angle * Deg2Rad);

	return temp;
}

Polar Comp2Polar(const Vector2& v)
{
	Polar temp;
	// ��Ÿ����� ������ �̿��Ͽ� ũ�⸦ ���.
	temp.magnitude = sqrtf(pow(v.x, 2) + pow(v.y, 2));
	// divide-by-zero(�и� 0) ������ �������� �۾�.
	if (0 == temp.magnitude) return temp;
	// ���� ���. ��1, 4�и��� ���� �����ϴ� asin�� ���.
	temp.angle = Rad2Deg * asin(v.y / temp.magnitude);
	// ���� ��2, 3�и鿡 ���� ���.
	if (0 > v.x) temp.angle += 180;
	// ��4�и鿡 ���� ���.
	else if (0 < v.x && 0 > v.y) temp.angle += 360;

	return temp;
}
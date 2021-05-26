#pragma once
#include "vector2.h"


// ���� �ð��� �ӵ��� ���� �̵� �Ÿ�.
float Displacement(const float& velocity, const float& time)
{
	return velocity * time;
}

// �������� ������, �̵��� �ð��� ��� �ӵ�.
float AvgVelocity(const float& start, const float& end, const float& time)
{
	return (end - start) / time;
}

// ���� �ð��� ���ӵ��� ���Ѵ�.
// ���� �ӵ�, ���� �ӵ�, ���� ���� ������� �ɸ� �ð�.
float AccelerationSeconds(const float& startVel, const float& endVel, const float& time)
{
	return (endVel - startVel) / time;
}
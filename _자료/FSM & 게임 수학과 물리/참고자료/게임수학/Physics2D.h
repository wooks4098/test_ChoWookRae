#pragma once
#include "vector2.h"


class GameObject
{
private:
	Vector2 pos;
	Vector2 velocity;

public:
	void UpdatePos()
	{
		pos += velocity;
	}

	// ���� ���� ���ӵ� ������Ʈ.
	// ��ī��Ʈ ��ǥ�� ���� ���ӵ��� ����� �Ʒ��� ��������.
	void UpdateVelocity(const float& accel, const float& deltaTime)
	{
		velocity.y = velocity.y + accel * deltaTime;
	}
};

// �������� ��ü�� ���Ը� ���.
Vector2 Weight(const float& mass)
{
	Vector2 weight;

	weight.y = mass * GRAVITY;

	return weight;
}

// ��ü�� ������ �̲��������� üũ.
// �̲������� true, �ƴϸ� false
bool IsSlopeSlip(const float& angle, const float& weight, const float& coeffFric)
{
	// ���鿡�� ��ü�� �ۿ��ϴ� �����׷� ���.
	float normal = weight * cosf(angle * Deg2Rad);
	// ���鿡 �����ϰ� ��ü�� �ۿ��ϴ� �� ���.
	float perpForce = weight * sinf(angle * Deg2Rad);
	// ��ü�� ������ �ֵ��� �ϴ� ���������� ���.
	float staticFriction = coeffFric * normal;
	
	return (perpForce > staticFriction);
}

// ���鿡�� �̲����� �������� ���ӵ� ���.
float SlopeSlipAccel(const float& angle, const float& weight, const float& coeffFric, const float& mass)
{
	// ���鿡�� ��ü�� �ۿ��ϴ� �����׷� ���.
	float normal = weight * cosf(angle * Deg2Rad);
	// ���鿡 �����ϰ� ��ü�� �ۿ��ϴ� �� ���.
	float perpForce = weight * sinf(angle * Deg2Rad);
	// ��ü�� �ۿ��ϴ� ������� ���.
	float kineticFriction = coeffFric * normal;
	// ��ü�� �ۿ��ϴ� �� ���.
	float totalForce = perpForce - kineticFriction;
	// ��ü�� ���ӵ�.
	return (totalForce / mass);
}

// ��(��ü�� ���� �ۿ��� ���� �������� ��ü�� �̵���Ű�� ��)�� ��.
float Work(const float& force, const float& friction, const float& displacement)
{
	float netForce = force - friction;
	return displacement * netForce;
}

// ���� ����Ͽ� ���� ���.
float AngleWork(const Polar& p, const float& friction, const float& displacement)
{
	float temp = cos(p.angle * Deg2Rad);
	// ���� ���� ���� ���.
	float horizForce = p.magnitude * temp;
	
	return Work(horizForce, friction, displacement);
}

// inital:��ü�� �ۿ�� ��, chage:�ܺ��� �������� ���Ͽ� ���� �ۿ��� ��.
float AngleWorkFromVector(const Polar& inital, const Polar& chage)
{
	// �� ��ǥ�� ��ī��Ʈ ��ǥ�� ����.
	auto force = Polar2Comp(inital);
	auto displacement = Polar2Comp(chage);

	// ������ ����ȭ.
	auto displacementNormal = displacement.normalize();

	// ������ ����. ������ �������Ϳ� ���� ����.
	auto projectionLenth = DotProduct(force, displacementNormal);

	// ������ ���̿� ������ ���������� ��.
	auto temp = displacementNormal * projectionLenth;
	// ���� ����ϱ� ���� ����ǥ �������� �ٽ� ��ȯ.
	auto polarTemp = Comp2Polar(temp);

	return polarTemp.magnitude * chage.magnitude;
}

// ������ �ӷ��� �޾� � ������ ���.
float KineticEnergy(const float& mass, const float& speed)
{
	return (mass * 0.5f) * (pow(speed, 2));
}

// ��-������ ����.
// ��ü�� ���� �ӵ��� ���.
float WorkEnergy(const float& force, const float& mass, const float& displacement, const float& velocityInital)
{
	// �������� �������� �ʴ� ��Ȳ�� ����.
	float work = Work(force, 0, displacement);
	float result = work / (mass * 0.5f) - KineticEnergy(mass, velocityInital);
	// ���� �ӵ�.
	return sqrtf(result);
}

// ���ټ� �������� �� ������ ���.
float PotentialEnergy(const float& mass, const float& height)
{
	return mass * GRAVITY * height;
}

// ���� ���ĵ� ������ �ݻ� ����.
Vector2 AxisAlignedCollision(const Vector2& v, bool isHorizen)
{
	Vector2 temp = v;
	if (!isHorizen) temp.x *= -1;
	else temp.y *= -1;

	return temp;
}

// ���� ������ ������ �ݻ�.
// v1:�ݻ�鿡 ������ ����, v2:�Ի纤��
Vector2 NonAxisAlignedCollision(const Vector2& v1, const Vector2& v2)
{
	// ���� ����ȭ.
	auto normal = Normalize(v1);

	// ���� ����.
	auto revalsal = ScalarMultiply(v2, -1);

	// �������� ������ ���̸� ���.
	auto projection = DotProduct(revalsal, normal);

	auto length = ScalarMultiply(normal, projection);

	// �ݻ� ���͸� ���ϱ� ���ؼ� 2��� ��.
	auto reflection = ScalarMultiply(length, 2);

	return SumVector(reflection, revalsal);
}
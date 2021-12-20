#pragma once

#include "Object.h"

class Arrow : public Object
{
public:
	explicit Arrow() : Object() {}

	void Update() override;
	void SetAngles(float xAngle, float yAngle, float zAngle);

private:
	float m_xAngle = 0;
	float m_yAngle = 0;
	float m_zAngle = 0;
};


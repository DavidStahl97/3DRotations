#include "pch.h"
#include "Arrow.h"
#include "Content/ShaderStructures.h"

using namespace DirectX;

void Arrow::SetAngles(float xAngle, float yAngle, float zAngle) 
{
	m_xAngle = xAngle;
	m_yAngle = yAngle;
	m_zAngle = zAngle;
}

void Arrow::Update() 
{
	auto rotationMatrix = XMMatrixRotationX(m_xAngle) * XMMatrixRotationY(m_yAngle) * XMMatrixRotationZ(m_zAngle);
	XMStoreFloat4x4(&m_View, rotationMatrix);
}
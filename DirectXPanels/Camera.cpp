#include "pch.h"
#include "Camera.h"

using namespace DirectX;

void Camera::Update() 
{
	static const XMVECTORF32 at = { 0.0f, 0.0f, 0.0f, 0.0f };
	static const XMVECTORF32 up = { 0.0f, 1.0f, 0.0f, 0.0f };

	auto& zero = XMVectorSet(0, 0, 1, 0);

	auto& phiRotationVector = XMVector4Transform(zero, XMMatrixRotationY(m_Phi));
	auto& eye = m_Distance * XMVector4Transform(phiRotationVector,
		XMMatrixRotationAxis(
			XMVector3Cross(phiRotationVector, XMVectorSet(0, 1, 0, 0)), m_Epsilon));

	XMStoreFloat4x4(&m_View, XMMatrixTranspose(XMMatrixLookAtRH(eye, at, up)));
}

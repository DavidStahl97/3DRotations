#include "pch.h"
#include "Camera.h"

using namespace DirectX;

void Camera::Update() 
{
	static const XMVECTORF32 eye = { 0.0f, 0.7f, 1.5f, 0.0f };
	static const XMVECTORF32 at = { 0.0f, -0.1f, 0.0f, 0.0f };
	static const XMVECTORF32 up = { 0.0f, 1.0f, 0.0f, 0.0f };

	XMStoreFloat4x4(&m_View, XMMatrixTranspose(XMMatrixLookAtRH(eye, at, up)));
}
